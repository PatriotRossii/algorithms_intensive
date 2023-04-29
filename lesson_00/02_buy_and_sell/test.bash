#!/bin/bash

for infile in tests/*.input; do
    basename=${infile%.*}
    (./a.out <  $infile) > $basename.output
    echo $infile
    diff $basename.output $basename.solution
done

rm -rf tests/*.output
