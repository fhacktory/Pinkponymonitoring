#!/bin/bash
#
# Nb de connexion établie sur le port 21
#

# INIT
./scripts/src/init.sh

# VAR
TMP_PATH="/tmp/nb_sock_p21.tmp"
PORT=21

# CHECK
command -v netstat 2>&1 >> /dev/null 
if [[ $? -ne 0 ]]; then
    echo "COMMAND NOT FOUND: netstat"
    exit 1
fi
command -v egrep 2>&1 >> /dev/null 
if [[ $? -ne 0 ]]; then
    echo "COMMAND NOT FOUND: egrep"
    exit 1
fi
command -v grep 2>&1 >> /dev/null 
if [[ $? -ne 0 ]]; then
    echo "COMMAND NOT FOUND: grep"
    exit 1
fi
command -v tr 2>&1 >> /dev/null 
if [[ $? -ne 0 ]]; then
    echo "COMMAND NOT FOUND: tr"
    exit 1
fi
command -v cut 2>&1 >> /dev/null 
if [[ $? -ne 0 ]]; then
    echo "COMMAND NOT FOUND: cut"
    exit 1
fi
command -v uniq 2>&1 >> /dev/null 
if [[ $? -ne 0 ]]; then
    echo "COMMAND NOT FOUND: uniq"
    exit 1
fi

# EXEC
netstat -an | egrep ".*:$PORT" | tr -s " " | cut -f6 -d " " | sort | uniq -c | grep ESTABLISHED | tr -s ' ' | cut -d ' ' -f 2 > $TMP_PATH
if [ -s $TMP_PATH ]; then
    cat $TMP_PATH
else
    echo 0
fi
exit 0
