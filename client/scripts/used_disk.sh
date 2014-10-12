#
# Affiche le % d'espace disque utilisé
#

# INIT
./scripts/src/init.sh

# VAR
TMP_FILE="src/df.data.tmp"

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
cat scripts/src/df.data | grep "/dev/" >> $TMP_FILE

while read line  
do  
   line=`echo $line | sed -e "s/  / /g" | sed -e "s/  / /g" | sed -e "s/  / /g" | sed -e "s/  / /g" | sed -e "s/  / /g"`
   used=`echo $line | cut -d ' ' -f 5`
   mount=`echo $line | cut -d ' ' -f 6`
   mount=`echo $mount | tr '/' '-'`
   mount=`echo $mount | tr '/' '-'`
   mount=`echo $mount | tr '/' '-'`
   mount=`echo $mount | tr '/' '-'`
   mount=`echo $mount | tr '/' '-'`
   used=`echo $used | tr -s '%'`
   echo -n $mount
   echo "_$used"
done < $TMP_FILE
rm $TMP_FILE
exit 0
