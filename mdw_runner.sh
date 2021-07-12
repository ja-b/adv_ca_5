#!/bin/bash
#SBATCH --account=mpcs52018
#SBATCH --time=02:00
#SBATCH --output=run_output.txt
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=1
#SBATCH --exclusive

./dotp_omp 1
