FROM ubuntu:latest

RUN apt -y update
RUN apt -y upgrade
RUN apt -y install gcc git wget make libncurses-dev flex bison gperf python3 python3-pip python-is-python3
RUN pip install pyserial

RUN mkdir -p /esp
WORKDIR /esp

RUN wget -qO- https://dl.espressif.com/dl/xtensa-lx106-elf-gcc8_4_0-esp-2020r3-linux-amd64.tar.gz | tar xvz

RUN git clone --recursive https://github.com/espressif/ESP8266_RTOS_SDK.git esp-idf

ENV PATH="$PATH:$HOME/esp/xtensa-lx106-elf/bin"
ENV IDF_PATH=/esp/esp-idf

RUN pip install --user -r $IDF_PATH/requirements.txt