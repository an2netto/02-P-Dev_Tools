#!/bin/bash

filename=sine2000.wav
echo "Measuring dft performance with"
for i in {0..2000..100}
do
        echo "$i samples..."
        echo -n "$i " >> num-items.tmp
        echo -n "$(./dft_main_O0 $filename $i) " >> time_diff_O0.tmp
        echo -n "$(./dft_main_O1 $filename $i) " >> time_diff_O1.tmp
        echo -n "$(./dft_main_O2 $filename $i) " >> time_diff_O2.tmp
        echo -n "$(./dft_main_O3 $filename $i) " >> time_diff_O3.tmp
        echo -n "$(./dft_main_Os $filename $i) " >> time_diff_Os.tmp
done

echo | tee -a *.tmp > /dev/null

echo "Merging data..."
cat *.tmp > data.txt

echo "Cleaning up temporary files..."
rm *.tmp

echo "Plotting results to image..."
./plot.py

echo Done

