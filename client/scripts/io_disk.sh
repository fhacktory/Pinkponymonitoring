#
# Affiche le % d'utilisation des IO disque
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
command -v iostat 2>&1 >> /dev/null 
if [[ $? -ne 0 ]]; then
    echo "COMMAND NOT FOUND: iostat(pkg sysstat)"
    exit 1
fi

# EXEC
cat src/io.data | grep sd | sed -e "s/  / /g" | sed -e "s/  / /g" | sed -e "s/  / /g" | sed -e "s/  / /g" | sed -e "s/  / /g" | cut -d ' ' -f 14
exit 0
