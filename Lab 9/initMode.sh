#!/bin/bash
# 0 RED, 1 BLUE, 2 YELLOW, 3 GREEN, 4 BUZZER, 5 BUTTON

for value in {0..4}
do
	echo $value
	gpio mode $value out
	gpio write $value 0
done

        gpio mode 5 in
        gpio mode 5 up


echo All done
