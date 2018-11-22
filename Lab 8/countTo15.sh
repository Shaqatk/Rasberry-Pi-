#!/bin/bash
./initMode.sh


for var in {0..15}
do
	./setbits.sh "$var"
	sleep 1
done

echo All done
