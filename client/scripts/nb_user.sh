#
# Affiche le nombre d'utilisateurs connectés
#

# INIT
./scripts/src/init.sh

# CHECK
command -v who 2>&1 >> /dev/null 
if [[ $? -ne 0 ]]; then
    echo "COMMAND NOT FOUND: who"
    exit 1
fi
command -v wc 2>&1 >> /dev/null 
if [[ $? -ne 0 ]]; then
    echo "COMMAND NOT FOUND: wc"
    exit 1
fi

# EXEC
who | wc -l
exit 0