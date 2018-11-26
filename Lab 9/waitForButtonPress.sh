#!/bin/bash

echo "waiting for button press"

until [ $(gpio read 5) -eq 0 ]
do
	echo "button not pressed"

done

 until [ $(gpio read 5) -eq 1 ]
  do
        echo "button pressed"
  done

echo All done
