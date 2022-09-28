#!/bin/bash
echo "enter username"
read USERNAME
$USERNAME
grep -R -l m  /home | ls -alR | grep ' $USERNAME ' | grep -e "-r[w-][x-][r-][w-][x-][r-][w-][x-]"