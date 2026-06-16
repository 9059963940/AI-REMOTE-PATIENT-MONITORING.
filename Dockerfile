FROM ubuntu:22.04

RUN apt update

RUN apt install -y \
g++ \
cmake \
sqlite3

WORKDIR /app

COPY . .

RUN mkdir build

WORKDIR build

RUN cmake ..

RUN make

CMD ["./RemotePatientMonitoring"]