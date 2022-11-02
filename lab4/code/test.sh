#!/bin/bash
parent_path=$( cd "$(dirname "${BASH_SOURCE[0]}")" ; pwd -P )

cd "$parent_path"

xmake b

cd "$parent_path"/..

cat ./data/0.txt | xmake r lab4_scheduler >> ./data/0.res.txt
cat ./data/1.txt | xmake r lab4_scheduler >> ./data/1.res.txt
cat ./data/2.txt | xmake r lab4_scheduler >> ./data/2.res.txt
cat ./data/3.txt | xmake r lab4_scheduler >> ./data/3.res.txt
cat ./data/4.txt | xmake r lab4_scheduler >> ./data/4.res.txt
cat ./data/5.txt | xmake r lab4_scheduler >> ./data/5.res.txt
cat ./data/6.txt | xmake r lab4_scheduler >> ./data/6.res.txt
cat ./data/7.txt | xmake r lab4_scheduler >> ./data/7.res.txt
cat ./data/8.txt | xmake r lab4_scheduler >> ./data/8.res.txt
cat ./data/9.txt | xmake r lab4_scheduler >> ./data/9.res.txt
