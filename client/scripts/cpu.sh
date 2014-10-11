#
# Affiche le % d'utilisation du CPU
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
id_percent=`cat src/top.data | grep "%Cpu(s)" | cut -d ' ' -f 11`
id_percent_round=`echo $id_percent | cut -d '.' -f 1`
utilisation_percent=$((100 - id_percent_round))
echo $utilisation_percent
exit 0