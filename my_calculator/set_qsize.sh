#!/bin/bash

sudo rmmod qdma-pf
sudo insmod /home/sangmyeon.yoon/dma_ip_drivers/QDMA/linux-kernel/driver/src/qdma-pf.ko
# sudo modprobe -r qdma-pf
# sudo modprobe qdma-pf mode=0x0a:0:2

echo 1024 > /sys/bus/pci/devices/0000:0a:00.0/qdma/qmax
echo 2 > /sys/bus/pci/devices/0000:0a:00.0/qdma/intr_rngsz
