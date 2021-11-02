chmod a-x _ex3.txt > ex3.txt
chmod uo+rwx _ex3.txt >> ex3.txt
chmod g=u _ex3.txt >> ex3.txt
echo "660 means read/write permissions for owner and group and no permissions for others" >> ex3.txt
echo "775 means all permissions for owner and group and read/execute permissions for others" >> ex3.txt
echo "777 means all permissions for owner, group and others" >> ex3.txt
