#!/bin/bash

git add .
git commit -m "`fortune -s`"
git push origin master

ssh pi@raspiclock -- "cd /home/pi/Development/QPiClock; DISPLAY=:0 ./build.sh"
