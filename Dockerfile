FROM debian:buster-slim
RUN apt-get update && apt-get -y upgrade && apt-get install -y git build-essential clang valgrind \
    && mkdir -m 666 /project
WORKDIR /project