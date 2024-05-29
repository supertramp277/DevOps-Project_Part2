Bootstrap: docker
From: ubuntu:20.04

%labels
    Author YourName
    Version 1.0

%post
    # Install necessary dependencies
    apt-get update && apt-get install -y \
        mpich \
        libmpich-dev \
        cmake \
        build-essential \
        git \
        && rm -rf /var/lib/apt/lists/*

    # Copy project files
    mkdir -p /opt/matrix_mult
    cp -r D:\Code Learning\Github\DevOps-Project_Part2/* /opt/matrix_mult

    # Build the project
    cd /opt/matrix_mult
    mkdir build && cd build
    cmake ..
    make

%test
    cd /opt/matrix_mult/build
    ctest

%runscript
    exec /opt/matrix_mult/build/main
