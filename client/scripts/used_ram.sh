#
# Affiche le % de RAM utilisé
#

# INIT
./src/init.sh

# CHECK
command -v cat 2>&1 >> /dev/null 
if [[ $? -ne 0 ]]; then
    echo "COMMAND NOT FOUND: cat"
    exit 1
fi
command -v grep 2>&1 >> /dev/null 
if [[ $? -ne 0 ]]; then
    echo "COMMAND NOT FOUND: grep"
    exit 1
fi
command -v cut 2>&1 >> /dev/null 
if [[ $? -ne 0 ]]; then
    echo "COMMAND NOT FOUND: cut"
    exit 1
fi

# EXEC
used=`cat src/free.data | grep Mem | cut -d ' ' -f 19`
total=`cat src/free.data | grep "Mem:" | cut -d ' ' -f 11`
used_percent=`echo "$(($used * 100 / $total))"`
echo $used_percent
exit 0