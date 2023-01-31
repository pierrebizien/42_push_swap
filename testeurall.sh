#!/bin/bash
clear && make re
for i in  1 2 3 4 5 10 20 30 50 100 500
do
    bash push_swap_tester/tester.sh . $i 25
done