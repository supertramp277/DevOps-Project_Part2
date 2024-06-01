#!/bin/bash

# Set job name
#SBATCH --job-name=matrix_mult_job

# Redirect output and error
#SBATCH --output=matrix_mult_output.txt
#SBATCH --error=matrix_mult_error.txt

# Set Parameters
#SBATCH --ntasks=4
#SBATCH --time=01:00:00

# Run the containerized application
cd build
cmake ..
make
ctest