#! bin/bash

DNA1=$1
DNA2=$2

LEN1=${#DNA1}
LEN2=${#DNA2}

DIFF=""

if [ $LEN1 != $LEN2 ]; then
	echo "Strings don't have same length!"
else
	echo "Strings have same length!"
	for((i=0;i<$LEN1;i++))
	do 
		if [ ${DNA1:i:1} != ${DNA2:i:1} ]; then
			COUNTER=$[COUNTER+1]
			DIFF="$DIFF^"
		else
			DIFF="$DIFF "	
		fi
	done
fi

echo "$DNA1"
echo "$DNA2"
echo "$DIFF"

