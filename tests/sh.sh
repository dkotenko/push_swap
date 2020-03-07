cat perm.txt|while read line; do
	echo $line | cat -e && ./push_swap "$line" && sleep 0.1;
done