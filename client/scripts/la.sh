#!/bin/bash
#
# Affiche le loadaverage
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
command -v cut 2>&1 >> /dev/null
if [[ $? -ne 0 ]]; then
    echo "COMMAND NOT FOUND: cut"
    exit 1
fi
command -v tr 2>&1 >> /dev/null
if [[ $? -ne 0 ]]; then
    echo "COMMAND NOT FOUND: tr"
    exit 1
fi


# EXEC
cat scripts/src/top.data | grep 'top -' | tr -s ' ' | cut -d ' ' -f 12 | tr ',' '.' | cut -d '.' -f 1-2
exit 0
