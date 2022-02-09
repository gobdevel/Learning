#!/bin/bash

CUR_DIR=`pwd`
REMOTE_DIR='/root/build'
DOCKER_IMAGE='gob/alpine-cpp-dev'
DOCEKER_RUN="docker container run --rm  -v ${CUR_DIR}:${REMOTE_DIR}  -w=${REMOTE_DIR} ${DOCKER_IMAGE} "

if [ $# -lt 1 ]; then
    echo "Invalid Arguments !!! Usage : $0 -b | -c "
    exit -1
fi

command=$1

if [ "$command" = '-b' ]; then
    echo "${DOCEKER_RUN} make"
    ${DOCEKER_RUN} make
elif  [ "$command" = '-c' ]; then
    echo "${DOCEKER_RUN} clean"
    ${DOCEKER_RUN} make clean
else
    echo "Invalid Arguments !!! Usage : $0 -b | -c "
fi

