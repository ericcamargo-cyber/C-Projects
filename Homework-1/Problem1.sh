#!/bin/bash
echo "enter username"
read USERNAME
$USERNAME
echo "enter pathname"
read PATHNAME
$PATHNAME
grep -R -l m  /$PATHNAME | ls -alR | grep  $USERNAME  | grep -e "-r[w-][x-][r-][w-][x-][r-][w-][x-]"