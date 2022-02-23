# Parallel Computing
>  Using parallelization protocols/standards for acceleration algorithm's performance



## Table of contents
* [General Info](#general-information)
* [Features](#Features)
* [Prerequisites](#prerequisites)
* [Setup](#setup)
* [How to run](#how-to-run)
* [Acknowledgements](#acknowledgements)


## General Information
OpenMP Application Protocol Interface (API) and subset of functions of POSIX threads standard (pthreads) to speed up the Smith-Waterman algorithm for local
alignment of sequences. A simplified form of omega statistic, to detect positive selection in DNA sequences. Exports performance statistics. 
Applied for N random data.
 

## Features/Parallization
* Serial program on SW algorithm
* Parallel	Programming	Models (Jam, Unroll)
* Standards (SSE, OpenMP, Pthreads)

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
### Reference
1. Run in command-line flags and arguments on linux terminal
```
./<project name> -name ID -input PATH -match INT1 -mismatch INT2 -gap INT3
```
where 
* ID => string for .out file
* PATH => .txt path
* INT => int variable


### OpenMP
1. GCC installation
```
$ gcc --version
$ sudo apt install gcc
```
2. OpenMP config
```
$ echo |cpp -fopenmp -dM |grep -i open
$ sudo apt install libomp-dev
$ export OMP_NUM_THREADS=8
```

### Pthreads

## Setup


## Acknowledgements
[^1]: https://cs.stanford.edu/people/eroberts/courses/soco/projects/computers-and-the-hgp/smith_waterman.html
[^2]: https://en.wikipedia.org/wiki/Smith-Waterman_algorithm
[^3]: https://en.wikipedia.org/wiki/Smith-Waterman_algorithm#Linear
[^4]: https://computing.llnl.gov/tutorials/openMP/
[^5]: http://www.openmp.org
[^6]: https://computing.llnl.gov/tutorials/pthreads/
[^7]: http://www.cs.cmu.edu/afs/cs/academic/class/15492-f07/www/pthreads.html
[^8]: https://www.ibm.com/developerworks/library/l-posix1/




# How to run
Run script.h to compile and run all the files. Script must be executable to run it. Script  variables are initialized with number of sampling N = 10000000 for all implementations. The number of threads used is 2 or 4. The number of processors is 2 or 4.
