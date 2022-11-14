grep -o '\w*' words.txt | sort | uniq -c | sort -nr | awk '{print $2 " " $1}'
#grep -o '\w*' words.txt | awk '{seen[$0]++} END{for(s in seen){print s,seen[s]}}' | sort -k2r
