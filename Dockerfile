FROM ubuntu:18.04

RUN apt update && apt install -y g++ build-essential clang-6.0 libasound2-dev git
WORKDIR TFStubserver
COPY . .
RUN make
RUN rm -rf .git

CMD src/stubserver/stub
