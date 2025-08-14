#!/bin/bash

# This shell script initializes QDMA driver

dma-ctl qdma0a000 q add idx 1 mode mm dir h2c
dma-ctl qdma0a000 q add idx 1 mode mm dir c2h
dma-ctl qdma0a000 q start idx 1 dir h2c
dma-ctl qdma0a000 q start idx 1 dir c2h
