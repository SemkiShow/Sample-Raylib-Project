#!/bin/bash

set -e

if [ ! -f settings.txt ] || [ "$1" == "" ]; then
    printf "vsync=true\nshow-fps=true\n" > settings.txt
fi
