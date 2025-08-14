#!/bin/bash
BAR_ADDR=0xfb440000        # 1단계에서 찾은 BAR 2의 물리 시작 주소
OFFSET=0x0                 # BAR 시작점으로부터의 오프셋 (옵션)
READ_BYTES=640              # 읽고 싶은 바이트 수

# 최종 실행 명령어
busybox dd if=/dev/mem bs=1 skip=$(($BAR_ADDR + $OFFSET)) count=$READ_BYTES | busybox hexdump -C
