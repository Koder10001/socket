#!/bin/bash

bun run nodemon -e c,h --exec "make clean  && make && sudo ./socket || exit 1"