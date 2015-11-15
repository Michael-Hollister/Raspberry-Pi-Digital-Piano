# This source code is subject to the terms of The MIT License.
# If a copy of The MIT License was not distributed with this file,
# you can obtain one at http://opensource.org/licenses/MIT.

CFLAGS=-std=c++14 -Wall -Wextra -Werror -O2

Raspberry-Pi-Digital-Piano: Main.cpp
	g++ $(CFLAGS) -o Raspberry-Pi-Digital-Piano Main.cpp
