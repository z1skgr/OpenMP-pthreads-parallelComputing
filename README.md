# Parallel Computing
>  Using parallelization protocols/standards for acceleration algorithm's performance



## Table of contents
* [General Info](#general-information)
* [Features](#features)
* [Prerequisites](#prerequisites)
* [Setup](#setup)
* [How to run](#how-to-run)
* [Acknowledgements](#acknowledgements)


## General Information
_**OpenMP Application Protocol Interface (API)**_ and subset of functions of _**POSIX threadsstandard (pthreads)**_ to speed up the [Smith-Waterman algorithm](https://cs.stanford.edu/people/eroberts/courses/soco/projects/computers-and-the-hgp/smith_waterman.htm) for local
alignment of sequences. A simplified form of omega statistic, to detect positive selection in DNA sequences. Exports performance statistics. Applied for *N* random data.
 

## Features
* Serial program on SW algorithm [^2][^3]
* Parallel Standards (_OpenMP[^3][^4], Pthreads[^5][^6][^7]_)

Benchmarked on Intel(R) Core(TM) i7-1065G7 @ 1.30GHz 1.50 GHz with 8GB DDR3 memory.

## Prerequisites 
* Input `.txt` files for test. D_SIZE number of pairs of sequences
of characters, with each sequence being on a separate line or extending to
more lines for ease of reading. Read input file and reserve D,Q variables with variables from command line. For more info, see [How to run](#how-to-run).

`dataset.txt`
```
2

Q:      abc
D:      xxxabxcxxxaabbcc

Q:      aaabcd
D:      abababcabababcd
```

* Understanding of the SW algorithm

## How to run

1. GCC installation
```
$ gcc --version
$ sudo apt install gcc
```
### Reference
1. Compile .c file
```
gcc -o newserial newserial.c
```

2. Run in command-line flags and arguments on linux terminal
```
./newserial -name ID -input PATH -match INT1 -mismatch INT2 -gap INT3
```
where 
* ID => string for .out file
* PATH => .txt path
* INT => int variable


### OpenMP

1. OpenMP config
```
$ echo |cpp -fopenmp -dM |grep -i open
$ sudo apt install libomp-dev
```

3. Setting the number of threads[^8]
```
$ export OMP_NUM_THREADS=8 
```

4. Run in command-line flags and arguments on linux terminal
```
gcc -fopenmp -o OMPX <OMPa.c>
./OMPX -name ID -input PATH -match INT1 -mismatch INT2 -gap INT3 -threads INT4
```
where  <br>
THREADS => num of threads , and X is the preference on OMP implementation (3 implementation of OMP based on task granularity [^10] the different computation-to-communication ratio)
* _OMPa_ : Fine grained
* _OMPb_ : Fine grained
* _OMPd_ : Course grained

### Pthreads

1. Run in command-line flags and arguments on linux terminal
```
gcc -pthread  POSIXX.c -o POSIXX.
./POSIXX -name ID -input PATH -match INT1 -mismatch INT2 -gap INT3 -threads INT4
```
where <br> X is the preference on POSIX implementation (2 implementation of POSIX based on task granularity [^9] the different computation-to-communication ratio)

* _POSIXa_ : Fine
* _POSIXc_ : Course


See `scripting.sh` [^10] for more..


# Setup
Script  variables initialized as:
* N = 10000000. 
* Threads = [2 4]
* Processors = [2 4].


## Acknowledgements
[^1]: 
[^1]: https://en.wikipedia.org/wiki/Smith-Waterman_algorithm
[^2]: https://en.wikipedia.org/wiki/Smith-Waterman_algorithm#Linear
[^3]: https://computing.llnl.gov/tutorials/openMP/
[^4]: http://www.openmp.org
[^5]: https://computing.llnl.gov/tutorials/pthreads/
[^6]: http://www.cs.cmu.edu/afs/cs/academic/class/15492-f07/www/pthreads.html
[^7]: https://www.ibm.com/developerworks/library/l-posix1/
[^8]: Default number of threads (ignoring this command) is defined from the specification of CPU
[^9]: https://en.wikipedia.org/wiki/Granularity_(parallel_computing)#:~:text=In%20parallel%20computing%2C%20granularity%20%28or%20grain%20size%29%20of,communication%20overhead%20between%20multiple%20processors%20or%20processing%20elements.
[^10]: Run `scripting.sh` to compile and run all files. Must be executable. 

