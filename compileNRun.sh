#!/bin/bash

bun run nodemon -e c,h --exec "make clean  && make && ./socket || exit 1"