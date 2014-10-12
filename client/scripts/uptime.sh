#!/bin/bash
#
# Affiche le uptime en heure
#

# INIT
./scripts/src/init.sh

# CHECK
command -v cat 2>&1 >> /dev/null 
if [[ $? -ne 0 ]]; then
    echo "COMMAND NOT FOUND: cat"
    exit 1
fi

# EXEC
sec=`cat /proc/uptime | cut -d ' ' -f 1 | cut -d '.' -f 1`
hours=$(($sec / 60 / 60))
echo $hours
exit 0