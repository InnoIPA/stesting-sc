#!/bin/bash
# Copyright (c) 2022 Innodisk crop.
# 
# This software is released under the MIT License.
# https://opensource.org/licenses/MIT

MODE=${1}
PLATFORM=${2:-"arm"}
LIBTYPE=${3:-"static"}

function update_version_info () {
    GIT_HASH=$(git rev-parse HEAD)
    GIT_BRANCH=$(git describe --tags)

    sed -i -e 's/'"#define STESTING_HASH.*"'/'"#define STESTING_HASH \"${GIT_HASH}\""'/g' ./inc/common.h
    sed -i -e 's/'"#define STESTING_VERSION.*"'/'"#define STESTING_VERSION \"${GIT_BRANCH}\""'/g' ./inc/common.h
}

function reset_version_info () {
    GIT_HASH="HASH"
    GIT_BRANCH="BRANCH"

    sed -i -e 's/'"#define STESTING_HASH.*"'/'"#define STESTING_HASH \"${GIT_HASH}\""'/g' ./inc/common.h
    sed -i -e 's/'"#define STESTING_VERSION.*"'/'"#define STESTING_VERSION \"${GIT_BRANCH}\""'/g' ./inc/common.h
}

update_version_info

case ${MODE} in
    bin)
        C_LIB_TYPE=""
        C_CC=""
        C_FORMAT=""
        if [ "$LIBTYPE" == "shared" ] ; then
            C_LIB_TYPE="-DSHAREDLIB=ON"
        fi
        if [ "$PLATFORM" == "cc" ] ; then
            C_CC="-DCROSSCOMPILE=ON"
        elif [ "$PLATFORM" == "x86" ] ; then
            C_FORMAT="-DX86=ON"
        fi
        cmake -H. "${C_CC}" "${C_LIB_TYPE}" "${C_FORMAT}" "-B_build_${PLATFORM}"
        cd "./_build_${PLATFORM}" || exit
        make
        cp ./stesting ../
        cd ../
    ;;
    downloadcc)
        if [ ! -d "gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu" ]; then
            wget https://releases.linaro.org/components/toolchain/binaries/latest-7/aarch64-linux-gnu/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu.tar.xz
            tar -xvf gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu.tar.xz -C ./
            sync
            rm -rf gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu.tar.xz
        fi
    ;;
    clean)
        rm -rf ./_build*
        rm -rf ./stesting
        rm -rf ./log.json
    ;;
    *)  
        echo "${0} <MODE> <PLATFORM> <LIBTYPE>"
        echo "    MODE:"
        echo "        bin, downloadcc, clean"
        echo "    PLATFORM:"
        echo "        arm(default), x86, cc"
        echo "    LIBTYPE:"
        echo "        static(default), shared"
    ;;
esac

reset_version_info
