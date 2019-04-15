#!/bin/bash

killall PiClock; git pull github master && qmake && make && ./PiClock

