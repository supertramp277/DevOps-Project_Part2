Bootstrap: docker
From: ubuntu:20.04

# Set timezone to Etc/UTC for tzdata.
TZ=Etc/UTC && \
    ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && \
    echo $TZ > /etc/timezone

%labels
    yanlong wang
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
    cp -r ./* /opt/matrix_mult/

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
