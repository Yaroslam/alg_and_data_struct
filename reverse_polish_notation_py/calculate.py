from Stack import Stack
from rpn_work import *
from operations import *

def calculate(rpn_string):
    num_stack = Stack()
    lenght = len(rpn_string)
    i = 0

    while i < lenght:
        num = ''
        sym = rpn_string[i]
        if isNum(rpn_string[i]):
            while rpn_string[i] != " ":
                num+=rpn_string[i]
                i+=1
            i+=1
            num_stack.push(int(num))
        else:
            if sym == "~":
                operand1 = num_stack.pop()
                num_stack.push(-1*operand1)
            if sym == "+":
                operand1 = num_stack.pop()
                operand2 = num_stack.pop()
                num_stack.push(sum(operand1, operand2))
            if sym == "-":
                operand1 = num_stack.pop()
                operand2 = num_stack.pop()
                num_stack.push(minus(operand2, operand1))
            if sym == "/":
                operand1 = num_stack.pop()
                operand2 = num_stack.pop()
                num_stack.push(div(operand2, operand1))
            if sym == "*":
                operand1 = num_stack.pop()
                operand2 = num_stack.pop()
                num_stack.push(mult(operand1, operand2))
            if sym == "^":
                operand1 = num_stack.pop()
                operand2 = num_stack.pop()
                num_stack.push(power(operand2, operand1))
            i+=2
    return num_stack.pop()
