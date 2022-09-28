#!/bin/bash
for a in {A..Z}; do
  for b in {A..Z}; do
    htmlend=".html"
    html="$a$b$htmlend"
    link="https://en.wikipedia.org/wiki/$a$b"
    wget $link -O $html
    lynx -dump -nolist $html > dump.txt
    rm $html
    grep -o "[[:alpha:]]*" dump.txt >> grepoutput.txt
  done
done

sort grepoutput.txt > sgrepoutput.txt
uniq -c sgrepoutput.txt > uniqoutput.txt
sort -s -nr -k 1,1 uniqoutput.txt > sortoutput.txt
head -15 sortoutput.txt
rm grepoutput.txt