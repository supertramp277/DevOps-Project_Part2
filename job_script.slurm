#!/bin/bash

# Set job name
#SBATCH --job-name=matrix_mult_job

# Redirect output and error
#SBATCH --output=matrix_mult_output.txt
#SBATCH --error=matrix_mult_error.txt

# Set Parameters
#SBATCH --time=01:00:00              # Time limit hrs:min:sec
#SBATCH --nodes=2                    # Number of nodes
#SBATCH --ntasks-per-node=4          # Number of MPI processes per node
#SBATCH --cpus-per-task=1            # Number of CPU cores per MPI process
#SBATCH --ntasks-per-socket=2        # Number of MPI processes per socket
#SBATCH --mem-per-cpu=2000           # Memory per CPU core (MB)


# Navigate to the build directory
cd build

# Run CMake to configure the project
singularity exec ../matrix_mult.sif cmake .. || { echo 'CMake configuration failed' ; exit 1; }

# Build the project
singularity exec ../matrix_mult.sif make || { echo 'Build failed' ; exit 1; }

# Run the tests
singularity exec ../matrix_mult.sif ctest || { echo 'Tests failed' ; exit 1; }
