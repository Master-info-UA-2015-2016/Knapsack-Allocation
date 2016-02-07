#!/bin/sh

#to change student to edit STUDENT_NAME
STUDENT_NAME="DEFAYE_Johan"

FILES_DIR="./resources/"

echo "file name : "$FILES_DIR$STUDENT_NAME.txt
echo ""

./Branch_and_bound $FILES_DIR$STUDENT_NAME.txt
