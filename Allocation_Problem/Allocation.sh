#!/bin/sh

#to change student to edit STUDENT_NAME
FILE_NAME="Allocation"

FILES_DIR="./"

echo "file name : "$FILES_DIR$FILE_NAME.txt
echo ""

./allocation_problem $FILES_DIR$FILE_NAME.txt
