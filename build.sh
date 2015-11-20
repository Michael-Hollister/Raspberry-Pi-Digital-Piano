#!/bin/bash

rm Raspberry-Pi-Digital-Piano
git pull https://github.com/Michael-Hollister/Raspberry-Pi-Digital-Piano.git
make
./Raspberry-Pi-Digital-Piano
