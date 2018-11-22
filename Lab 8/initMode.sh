#!/bin/bash
# 0 RED, 1 RED, 2 YELLOW, 3 BLUE

for value in {0..3}
do
	echo $value
	gpio mode $value out
	gpio write $value 0
done


echo All done
