#!/bin/bash
clear && make re
for i in  500
do
    bash push_swap_tester/tester.sh . $i 20
done