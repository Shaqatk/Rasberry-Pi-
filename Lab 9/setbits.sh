#!/bin/bash
# 0 RED, 1 BLUE, 2 YELLOW, 3 GREEN

for value in {0..3}
do
	gpio write $value $((($1 >> ($value)) & 1))    
done
