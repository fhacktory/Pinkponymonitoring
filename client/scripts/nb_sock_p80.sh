#
# Nb de connexion établie sur le port 80
#

# INIT
./scripts/src/init.sh

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
netstat -an | egrep ".*:80" | tr -s " " | cut -f6 -d " " | sort | uniq -c | grep ESTABLISHED | tr -s ' ' | cut -d ' ' -f 2 >> /tmp/nb_sock_p80.tmp
if [ -s /tmp/nb_sock_p80.tmp ]; then
    cat /tmp/nb_sock_p80.tmp
else
    echo 0
fi
exit 0
