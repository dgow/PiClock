#!/bin/bash

killall PiClock; git pull origin master && qmake && make && ./PiClock

