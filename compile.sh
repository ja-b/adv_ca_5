#!/bin/csh
set echo on
set EXE = $argv[1]

gcc -fopenmp -DOMP -O2 -I/usr/local/papi/6.0/include -c ${EXE}.c
gcc -fopenmp -DOMP -O2 -o ${EXE} ${EXE}.o -L/usr/local/papi/6.0/lib -lpapi

