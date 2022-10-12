#!/bin/python3

import math
import os
import random
import re
import sys

def gradingStudents(grades):
    
    for i in range(0,len(grades)):
        
        if grades[i] < 38:     #grade is less than 38 , no rounding occurs as the result will still be a failing grade
            continue
        else:
            temp = grades[i]
            te = temp % 5   #If the difference between grade and the next multiple of  5 is less than 3 , round  up to the next multiple of 5
            if te == 3:
                temp = temp + 2
                grades[i] = temp
            elif te == 4:
                temp = temp + 1
                grades[i] = temp
            else:
                continue
    return grades



if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    grades_count = int(input().strip())

    grades = []

    for _ in range(grades_count):
        grades_item = int(input().strip())
        grades.append(grades_item)

    result = gradingStudents(grades)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()