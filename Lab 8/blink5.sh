#!/bin/bash

./initMode.sh

for values in {1..5} 
do
	for val in {0..3}
	do
		gpio write $val 1
	done

	sleep 1

        for val in {0..3}
        do
                gpio write $val 0
        done

        sleep 1
done

echo All done
