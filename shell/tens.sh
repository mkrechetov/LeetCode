COUNTER=1
TARGET=10
cat file.txt | while read line
do
   if (( $COUNTER == $TARGET))
   then
      echo "${line}"
   fi
   COUNTER=$[$COUNTER +1]
done
