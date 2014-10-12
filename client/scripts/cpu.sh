#
# Affiche le % d'utilisation du CPU
#

# INIT
./scripts/src/init.sh

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

# EXEC
id_percent=`cat scripts/src/top.data | grep "%Cpu(s)" | tr -s ' ' | cut -d ' ' -f 8`
id_percent_round=`echo $id_percent | cut -d '.' -f 1`
utilisation_percent=$((100 - $id_percent_round))
echo $utilisation_percent
exit 0
