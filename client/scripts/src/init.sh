top -n 1 > scripts/src/top.data
free -m > scripts/src/free.data
df -h > scripts/src/df.data
iostat -x > scripts/src/io.data 2>/dev/null