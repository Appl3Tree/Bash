#!/bin/bash
read -p "Please enter your gross income (before taxes): " grossIncome

firstFruitsPercent=0.025
tithePercent=0.1

firstFruits=$(echo "scale=2; ($grossIncome * $firstFruitsPercent * 100) / 100" | bc)

echo -e "First Fruits (2.5%):\t$firstFruits"
grossIncome=$(echo "scale=2; (($grossIncome - $firstFruits) * 100) / 100" | bc)

tithe=$(echo "scale=2; ($grossIncome * $tithePercent * 100) / 100" | bc)

echo -e "Tithe (10%):\t\t$tithe"

