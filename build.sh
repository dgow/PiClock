#!/bin/bash

killall PiClock; git pull && qmake && make && ./PiClock

