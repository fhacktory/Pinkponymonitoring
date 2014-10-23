#!/bin/bash
#
# Affiche le % d'utilisation des IO disque
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
if [ -s "scripts/src/io.data" ]; then
    cat scripts/src/io.data | grep sd | tr -s ' ' | cut -d ' ' -f 12 | tr ',' '.'
else
    echo "NO DATA: iostat(pkg sysstat)"
    exit 1
fi
exit 0
