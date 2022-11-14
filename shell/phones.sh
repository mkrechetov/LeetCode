type1=^[\(][0-9]{1,3}[\)][" "][0-9]{1,3}["-"][0-9]{1,4}$
type2=^[0-9]{1,3}["-"][0-9]{1,3}["-"][0-9]{1,4}$
cat file.txt | while read line
do
   if [[ $line =~ $type1 ]] || [[ $line =~ $type2 ]] 
   then
      echo "${line}"
   fi
done
