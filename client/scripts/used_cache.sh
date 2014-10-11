#
# Affiche le % de Cache utilisé
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
cat src/free.data | grep Mem | cut -d ' ' -f 54
exit 0