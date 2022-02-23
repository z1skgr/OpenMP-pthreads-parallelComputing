# Parallel Computing
>  Using parallelization protocols/standards for acceleration algorithm's performance




## Table of contents
* [General Info](#general-information)
* [Features](#features)
* [Setup](#setup)
* [How to run](#how-to-run)
* [Acknowledgements](#acknowledgements)


## General Information
OpenMP Application Protocol Interface (API) and subset of functions of POSIX threads standard (pthreads) to speed up the Smith-Waterman algorithm for local
alignment of sequences. A simplified form of omega statistic, to detect positive selection in DNA sequences. Exports performance statistics. 
Applied for N random data.
 

## Features
* Serial program on SW algorithm
* Parallel	Programming	Models (Jam, Unroll)
* Standards (SSE, OpenMP, Pthreads)

Benchmarked on Intel(R) Core(TM) i7-1065G7 @ 1.30GHz 1.50 GHz with 8GB DDR3 memory.

## Prerequisites 
## How to run

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


# Parallelization <br />
Using reference file for parallelization. <br />
1)Intermidiate Steps(Jam,Unroll) for SSE. <br />
2)SSE. <br />
3)SSE with pthreads. <br />
4)SSE pthreads MPI.  <br />
5)Bonus.

Bonus implementation from different memory layout that gives better performance for implementation with SSE commands.


# How to run
Run script.h to compile and run all the files. Script must be executable to run it. Script  variables are initialized with number of sampling N = 10000000 for all implementations. The number of threads used is 2 or 4. The number of processors is 2 or 4.
