# Parallel Computing
> jam,unroll,SSE,pthreads


Benchmarked on Intel(R) Core(TM) i7-1065G7 @ 1.30GHz 1.50 GHz with 8GB DDR3 memory.

## Table of contents
* [General Info](#general-information)
* [Features](#features)
* [Setup](#setup)
* [How to run](#how-to-run)
* [Acknowledgements](#acknowledgements)


## General Information

## Features

## Prerequisites 
## How to run

## Setup

## Acknowledgements

# Description of projects <br />
Calculating a simplified form of omega statistic, as applied to detect positive selection in DNA sequences. The computation is applied for N random data. The program prints maximum,minimum and average data values. Also, it times the calculations. 
 
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
