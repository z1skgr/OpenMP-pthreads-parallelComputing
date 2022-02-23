#!/bin/bash

# Description :	Compile and run all the variations of the algorithm witn the same input.

echo "The script starts."
echo ""

#Compile the code.
gcc -o newserial newserial.c
gcc -fopenmp -o OMPa OMPa.c
gcc -fopenmp -o OMPb OMPb.c
gcc -fopenmp -o OMPb OMPd.c
gcc -pthread  POSIXa.c -o POSIXa
gcc -pthread  POSIXc.c -o POSIXc


#Script Variables.
Match="3"
Mismatch="-1"
Id="newserial"
Path="/home/zisk/Desktop/project/Datasets"
Threads="4"
Gap="-1"


echo "Scores: $Match, $Mismatch, $Gap"
echo "Strings: $Id , $Path"
echo "Threads: $Threads"
echo ""

#Serial execution.
echo "------------------->Serial<-------------------"
echo "------------------->Serial 1<-------------------"
echo ""
./newserial "-name" "$Id""1" "-path" "$Path/D1.txt" "-match" "$Match" "-mismatch" "$Mismatch" "-gap" "$Gap"
echo "------------------->Serial 2<-------------------"
echo ""
./newserial "-name" "$Id""2" "-path" "$Path/D2.txt" "-match" "$Match" "-mismatch" "$Mismatch" "-gap" "$Gap"
echo "------------------->Serial 3<-------------------"
echo ""
./newserial "-name" "$Id""3" "-path" "$Path/D3.txt" "-match" "$Match" "-mismatch" "$Mismatch" "-gap" "$Gap"
echo "------------------->Serial 4<-------------------"
echo ""
./newserial "-name" "$Id""4" "-path" "$Path/D4.txt" "-match" "$Match" "-mismatch" "$Mismatch" "-gap" "$Gap"
echo "------------------->Serial 5<-------------------"
echo ""
./newserial "-name" "$Id""5" "-path" "$Path/D5.txt" "-match" "$Match" "-mismatch" "$Mismatch" "-gap" "$Gap"
echo "------------------->Serial 9<-------------------"
echo ""
./newserial "-name" "$Id""9" "-path" "$Path/D9.txt" "-match" "$Match" "-mismatch" "$Mismatch" "-gap" "$Gap"
echo "------------------->Serial 10<-------------------"
echo ""
./newserial "-name" "$Id""10" "-path" "$Path/D10.txt" "-match" "$Match" "-mismatch" "$Mismatch" "-gap" "$Gap"



#Change Variables.
Id="OMPa"
echo ""
echo "####################OMP#####################"
echo "####################OMPa-9####################"
echo ""
#Parallel execution with OMP API.
./OMPa "-name" "$Id""9" "-path" "$Path/D9.txt" "-match" "$Match" "-mismatch" "$Mismatch" "-gap" "$Gap" "-threads" "$Threads"
echo "####################OMPa-10###################"
./OMPa "-name" "$Id""10" "-path" "$Path/D10.txt" "-match" "$Match" "-mismatch" "$Mismatch" "-gap" "$Gap" "-threads" "$Threads"
echo "####################OMPb####################"
echo ""
Id="OMPb"
echo "####################OMPb-9####################"
./OMPb "-name" "$Id""9" "-path" "$Path/D9.txt" "-match" "$Match" "-mismatch" "$Mismatch" "-gap" "$Gap" "-threads" "$Threads"
echo "####################OMPb-10####################"
./OMPb "-name" "$Id""10" "-path" "$Path/D10.txt" "-match" "$Match" "-mismatch" "$Mismatch" "-gap" "$Gap" "-threads" "$Threads"
echo ""
Id="OMPd"
echo "####################OMPd-9####################"
./OMPb "-name" "$Id""9" "-path" "$Path/D9.txt" "-match" "$Match" "-mismatch" "$Mismatch" "-gap" "$Gap" "-threads" "$Threads"
echo "####################OMPd-10####################"
./OMPb "-name" "$Id""10" "-path" "$Path/D10.txt" "-match" "$Match" "-mismatch" "$Mismatch" "-gap" "$Gap" "-threads" "$Threads"

echo ""
echo "%%%%%%%%%%%%%%%%%%%%Pthreads%%%%%%%%%%%%%%%%%%%%"
echo ""


#Change Variables.
Id="POSIXa"
echo ""
# # #Parallel execution with pthreads.
echo "%%%%%%%%%%%%%%%%%%%%POSIXa-9%%%%%%%%%%%%%%%%%%%%"
./POSIXa "-name" "$Id""9" "-path" "$Path/D9.txt" "-match" "$Match" "-mismatch" "$Mismatch" "-gap" "$Gap" "-threads" "$Threads"
echo "%%%%%%%%%%%%%%%%%%%%POSIXa-10%%%%%%%%%%%%%%%%%%%%"
./POSIXa "-name" "$Id""10" "-path" "$Path/D10.txt" "-match" "$Match" "-mismatch" "$Mismatch" "-gap" "$Gap" "-threads" "$Threads"
echo ""
#Change Variables.
Id="POSIXc"
echo "%%%%%%%%%%%%%%%%%%%%POSIXc-9%%%%%%%%%%%%%%%%%%%%"
./POSIXc "-name" "$Id""9" "-path" "$Path/D9.txt" "-match" "$Match" "-mismatch" "$Mismatch" "-gap" "$Gap" "-threads" "$Threads"
echo "%%%%%%%%%%%%%%%%%%%%POSIXc-10%%%%%%%%%%%%%%%%%%%%"
./POSIXc "-name" "$Id""10" "-path" "$Path/D10.txt" "-match" "$Match" "-mismatch" "$Mismatch" "-gap" "$Gap" "-threads" "$Threads"


