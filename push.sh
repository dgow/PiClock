#!/bin/bash

git add .
git commit -m "`fortune -s`"
git push

ssh pi@raspiclock -- "cd /home/pi/Development/QPiClock; DISPLAY=:0 ./build.sh"
