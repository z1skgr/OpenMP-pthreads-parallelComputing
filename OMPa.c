/*
            ======================================================
            + Name        :newserial.c                           +
            + Author      :Christos Z,                           +
            + Description :Open Mp formation.                    +
            + 													 +
            ======================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <omp.h>


FILE * fp;
FILE * fw;
int maxV;

double gettime(){

  struct timeval ttime;
  gettimeofday(&ttime, NULL);
  return ttime.tv_sec+ttime.tv_usec * 0.000001;
}

/*  Find integer parameters from terminal*/
int terminal1(int argc,char const *argv[],char* stringA){
    int thesis=0;
    if ( argc == 1 ) {
        printf( "No arguments were passed.\n" );
        exit(EXIT_FAILURE);
    }
    for(int i=0;i<argc;i++){
        if(strcmp(argv[i],stringA)==0){
            thesis=i;
            if(argv[thesis+1]==NULL){
                printf("Exit EXIT_FAILURE\n");
                exit(EXIT_FAILURE);
            }
            return atoi(argv[thesis+1]);
        }
    }
    printf("Exit EXIT_FAILURE\n");
    exit(EXIT_FAILURE);

}

/*  Find string parameters from terminal*/
const char* terminal2(int argc,char const *argv[],char* stringA){
    int thesis=0;
    if ( argc == 1 ) {
        printf( "No arguments were passed.\n" );
        exit(EXIT_FAILURE);
    }
    for(int i=0;i<argc;i++){
        if(strcmp(argv[i],stringA)==0){
            thesis=i;
            if(argv[thesis+1]==NULL){
                printf("Exit EXIT_FAILURE\n");
                exit(EXIT_FAILURE);
            }
            return argv[thesis+1];
        }
    }
    printf("Exit EXIT_FAILURE\n");
    exit(EXIT_FAILURE);
}

void readVariables(int* pairNum,int* Qmin,int* Qmax,int* Dmax){
	char* c=(char*)malloc(sizeof(char));
	fscanf(fp,"%s",c);
	fscanf(fp,"%d",pairNum);
	fscanf(fp,"%s ",c);
	fscanf(fp,"%d",Qmin);
	fscanf(fp,"%s ",c);
	fscanf(fp,"%d",Qmax);
	fscanf(fp,"%s ",c);
	fscanf(fp,"%d",Dmax);
	printf("Qmin:%d\n",*Qmin);
	printf("Qmax:%d\n",*Qmax);
	printf("Dmax:%d\n",*Dmax);
	free(c);
}

void readQ(int Qmax,char* Q){
    char* c=(char*)malloc(sizeof(char));
    fscanf(fp,"%s ",c);
    fputs("Q:\t",fw);
    int l;
    int i=0;
    while(i<Qmax){

        l=fgetc(fp);
        if(l==68)
            break;
        if(l==10 || l==9 || l==127)
                fseek(fp,0,SEEK_CUR);
        else{
            Q[i]=(char)l;
            putc(Q[i], fw);
            if((i+1)%100==0)
                fputs("\n\t",fw);
            i++;
        }

    }
    free(c);
 }

void readD(int Dmax,char* D){
    int i=0;
    char* c=(char*)malloc(sizeof(char));
    int l;
    fputs("\nD:\t",fw);
    fscanf(fp,"%c",c);
    while(i<Dmax){
        l=fgetc(fp);
        if(l==-1)
            break;
        if(l==10 || l==9 || l==127){
            fseek(fp,0,SEEK_CUR);
        }else{
            D[i]=(char)l;
            putc(D[i],fw);
            if((i+1)%100==0)
                fputs("\n\t",fw);
            i++;
        }
    }
    fseek(fw,-1,SEEK_CUR);
    free(c);

}

 
void traceback(char* Q,char *D,int maxi,int maxj,int** scoreTable){
    char BESTD[strlen(D)];
    char BESTQ[strlen(Q)];
    int count=-1;
    int tempj=maxj;
    int tempi=maxi;
    while(scoreTable[maxi][maxj]>0){
            count++;
            if(*(D+maxj-1)==*(Q+maxi-1)){
                BESTQ[count]=Q[maxi-1];
                BESTD[count]=D[maxj-1];
                maxi=maxi-1;
                maxj=maxj-1;
            }
            else if(scoreTable[maxi][maxj-1]>=scoreTable[maxi-1][maxj] && scoreTable[maxi][maxj-1]>=scoreTable[maxi-1][maxj-1]){
                BESTQ[count]=45;
                BESTD[count]=D[maxj-1];
                maxi=maxi;
                maxj=maxj-1;
            }else if(scoreTable[maxi-1][maxj-1]>scoreTable[maxi-1][maxj] && scoreTable[maxi-1][maxj-1]>=scoreTable[maxi][maxj-1]){
                BESTQ[count]=45;
                BESTD[count]=45;
                maxi=maxi-1;
                maxj=maxj-1;
            }else{
                BESTQ[count]=45;
                BESTD[count]=Q[maxi-1];
                maxi=maxi-1;
                maxj=maxj;
            }

     }

    fputs(",Start: ",fw);
    fprintf(fw,"%d",maxj);
    fputs(",Stop: ",fw);
    fprintf(fw,"%d",tempj);

     fputs("]\n\t",fw);
     fputs("D:",fw);
     for(int i=0;i<=count;i++){
        fprintf(fw,"%c",BESTD[count-i]);
        if((i+1)%100==0)
                fputs("\n\t  ",fw);
     }
     fputs("\n\tQ:",fw);

    for(int i=0;i<=count;i++){
        fprintf(fw,"%c",BESTQ[count-i]);
        if((i+1)%100==0)
                fputs("\n\t  ",fw);
     }
     fputs("\n\n",fw);

}

void calculation(char Q,char D,int** scoreTable,int i,int j,int match,int mismatch,int gap){
    int value;
    int num1=0;
    int num2=0;
    int num3=0;
    if(Q==D)
        value=scoreTable[i][j]+match;
    else{
        num1=scoreTable[i][j];
        num2=scoreTable[i+1][j];
        num3=scoreTable[i][j+1];
        if( num1+mismatch>=num2+gap && num1+mismatch>=num3+gap){
            if(num1+mismatch<0)
                value=0;
            else
                value=num1+mismatch;
                    }
        else if (num2+gap>num1+mismatch && num2+gap>num3+gap){
            if(num2+gap<0)
                value=0;
            else
                value=num2+gap;
            }
        else{
            if(num3+gap<0)
                value=0;
            else
                value=num3+gap;
            }              
        }
        scoreTable[i+1][j+1]=value; 
        if(maxV<value)
            maxV=value;
}



int main(int argc, char const *argv[]){
/*-----------------------------------------------------------*/
    double ExecTime1;
    double ExecTime2;
    double ExecTime;
    double calculateTime1;
    double calculateTime2;
    double calculateTime;
    double tracebackTime1;
    double tracebackTime2;
    double tracebackTime;
    float CUPSa;
    float CUPSb;

/*-----------------------------------------------------------*/

	printf("Hello\n");
	if (argc > 13 || argc < 1){//Wrong arguements
        printf("Non valid arguments\n");
        return -1;
    }
    ExecTime1=gettime();

	int match=terminal1(argc,argv,"-match");
	int mismatch=terminal1(argc,argv,"-mismatch");
	int gap=terminal1(argc,argv,"-gap");
	const char* ID=terminal2(argc,argv,"-name");
	const char* path=terminal2(argc,argv,"-path");
    int nthreads=terminal1(argc,argv,"-threads");
    char* ID2=(char*)ID;   
    char* Rept="Report_";
    char* txt=".txt";
    char* filename =(char*)malloc((strlen(Rept) + strlen(ID2) + 1+strlen(txt))*sizeof(char)); // +1 for the null-terminator

    strcpy(filename, Rept);
    strcat(filename, ID2);
    strcat(filename,txt);
	
	fp = fopen(path,"r");
    fw = fopen(filename,"w+");
    if(fw == NULL) {
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }else
    	printf("Creation File Successful\n");
/*-----------------------------------------------------------*/
    int pairNum;
    char* Q;
    char* D;
    int Qmin=0;//VARIABLES FROM FILE
    int Qmax=0;
    int Dmax=0;
/*-----------------------------------------------------------*/
 
	int i=0;
 	int j=0;
/*-----------------------------------------------------------*/
    printf("---->Dataset Arguements<----\n");
    readVariables(&pairNum,&Qmin,&Qmax,&Dmax);
    printf("----------------------------\n");
/*-----------------------------------------------------------*/
    int loop=pairNum;
    int times=0;
    int Dc=0;
    int Qc=0;
    int** scoreTable;
/*-----------------------------------------------------------*/
  	long long int cellsNum=0;
/*-----------------------------------------------------------*/
  	int tracestepsNum=0;
  	D=(char*)malloc(Dmax*sizeof(char));
    Q=(char*)malloc(Qmax*sizeof(char));
/*-----------------------------------------------------------*/

    while(loop>0){
    	times=0;
        maxV=0;


        readQ(Qmax,Q);
        readD(Dmax,D);
        
        Qc=strlen(Q);
        Dc=strlen(D);

        cellsNum=cellsNum+(Qc+1)*(Dc+1);

       	scoreTable = (int**) malloc((Qc+1)*sizeof(int*));
       	for (i = 0; i < strlen(Q)+1; i++){
           	scoreTable[i] = (int*) calloc((Dc+1),sizeof(int));
       	}
        calculateTime1=gettime();
        #pragma omp parallel shared(Q,D,scoreTable,match,mismatch,gap) num_threads(nthreads) private(i)
        {
                for(i=0;i<Qc;i++){
                       #pragma omp barrier
                        #pragma omp for nowait
                            for(j=0;j<Dc;j++){
                                calculation(Q[i],D[j],scoreTable,i,j,match,mismatch,gap);
                             }          
                }
            
        }
        calculateTime2=gettime();
        calculateTime=calculateTime+calculateTime2-calculateTime1;

        tracebackTime1=gettime();
		for(i=0; i<=Qc;i++){
            for(j=0;j<=Dc;j++){
                if(scoreTable[i][j]==maxV){
                    times++;
                    fputs("\n\nMatch ",fw);
                    fprintf(fw,"%d",times);
                    fputs("[Score: ",fw);
                    fprintf(fw,"%d",maxV);
                    traceback(Q,D,i,j,scoreTable);
                    tracestepsNum++;
                }
            }
        }
    
        tracebackTime2=gettime();
        tracebackTime=tracebackTime+tracebackTime2-tracebackTime1;
        
    	if(loop%200==0)
    	printf("Loading...\n");
        loop--;
    	for (i = 0; i < strlen(Q)+1; i++){
           	free(scoreTable[i]);
       	}
 	
    	
    }
    free(scoreTable);
    free(Q);
  	free(D);
    
    ExecTime2=gettime();
    ExecTime=ExecTime2-ExecTime1;
    

    CUPSa=cellsNum/ExecTime;
    CUPSb=cellsNum/calculateTime;



    printf("\n\n\nResults:");
    printf("\nA) Number of pairs Q-D:%d pair(s)",pairNum);//A
    printf("\nB) Number of cells:%lli cells",cellsNum);//B
    printf("\nC) Number of traceback steps:%d step(s)",tracestepsNum);//C
    printf("\nD) Execution Time:%f s",ExecTime);//D
    printf("\nE) Calculation Time:%f s",calculateTime);//E
    printf("\nF) Traceback Time:%f s",tracebackTime);//F
    printf("\nG) CUPS on execution time:%d cells",(int)(CUPSa+0.5));//G
    printf("\nH) CUPS on calculation time:%d cells",(int)(CUPSb+0.5));//H
    printf("\n");

    fclose(fp);
	fclose(fw);
	printf("\nFile Closed\n\n");

    return EXIT_SUCCESS;
}