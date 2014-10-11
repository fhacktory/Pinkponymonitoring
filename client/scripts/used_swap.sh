#
# Affiche le % de SWAP utilisé
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
command -v sed 2>&1 >> /dev/null 
if [[ $? -ne 0 ]]; then
    echo "COMMAND NOT FOUND: sed"
    exit 1
fi
command -v cut 2>&1 >> /dev/null 
if [[ $? -ne 0 ]]; then
    echo "COMMAND NOT FOUND: cut"
    exit 1
fi

# EXEC
used=`cat src/free.data | grep Swap | sed -e "s/  / /g" | sed -e "s/  / /g" | sed -e "s/  / /g" | sed -e "s/  / /g" | sed -e "s/  / /g" | cut -d ' ' -f 3`
total=`cat src/free.data | grep Swap | grep Swap | sed -e "s/  / /g" | sed -e "s/  / /g" | sed -e "s/  / /g" | sed -e "s/  / /g" | sed -e "s/  / /g" | cut -d ' ' -f 2`
if [[ $total -eq 0 ]]; then
    echo "100"
else
    used_percent=`echo "$(($used * 100 / $total))"`
    echo $used_percent
fi
exit 0
