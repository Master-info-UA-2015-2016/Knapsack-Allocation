#!/bin/sh

#to change student to edit STUDENT_NAME
STUDENT_NAME="GARNIER_Antoine"

FILES_DIR="./resources/"

echo "file name : "$FILES_DIR$STUDENT_NAME.txt
echo ""

./knapsack_branch-and-bound $FILES_DIR$STUDENT_NAME.txt
