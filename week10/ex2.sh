link ./week01/file.txt _ex2.txt > ex2.txt
find ./week01/file.txt -inum $(ls -i ./week01/file.txt | awk '{print $1}') >> ex2.txt
find ./week01/file.txt -inum $(ls -i ./week01/file.txt | awk '{print $1}') -exec rm {} \; >> ex2.txt
