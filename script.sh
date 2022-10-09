#!/usr/bin/env bash

# 'youtube-dl' -> to install youtube video
# 'premake5' -> to bundle source files into executable
set -xe

Packages=('youtube-dl' 'premake5' 'g++' 'make' 'jp2a' 'ffmpeg' )

for package in ${Packages[@]};do
               if ! command -v $package &> /dev/null
               then
                   echo "$package not found "
                   exit
               fi

            done
