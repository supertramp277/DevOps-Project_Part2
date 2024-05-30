Bootstrap: docker
From: ubuntu:20.04

%labels
    Author "Yanlong Wang"
    Version "1.0"

%post
    # Install necessary dependencies
    apt-get update && DEBIAN_FRONTEND=noninteractive apt-get install -y \
        mpich \
        libmpich-dev \
        cmake \
        build-essential \
        git \
        && rm -rf /var/lib/apt/lists/*

    # Create the project directory
    mkdir -p /opt/matrix_mult

    # Copy project files
    cp -r /workspace/* /opt/matrix_mult/

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
