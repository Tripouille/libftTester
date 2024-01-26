FROM debian:buster-slim

RUN apt-get update && apt-get -y upgrade
RUN apt-get install -y git build-essential clang valgrind

# Silence all warnings related to Git's safe.directory system.
RUN git config --global --add safe.directory '*'

RUN mkdir -m 666 /project
WORKDIR /project
