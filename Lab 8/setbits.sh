#!/bin/bash
# 0 RED, 1 RED, 2 YELLOW, 3 BLUE

for x in {0..3}
do
	gpio write $x $((($1 >> ($x)) & 1))
done 
