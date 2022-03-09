from Stack import Stack
from CONST import *


def validate(sym):
    isValid = True
    if sym not in NUMS:
        isValid = False
        if sym in PRIORITY_AND_OPERATIONS.keys():
            isValid = True
    return isValid


def isNum(sym):
    return sym in NUMS


def isSingleMinus(alg_primer, ind):
    isSingle = False
    if ind == 0:
        isSingle = True
    elif not (isNum(alg_primer[ind - 1])) and (alg_primer[ind - 1] != "^"):
        isSingle = True
    return isSingle


def get_prinority(sym):
    return PRIORITY_AND_OPERATIONS[sym]


def convert_to_rpn(alg_primer):
    lenght = len(alg_primer)
    rpn_string = ''
    rpn_stack = Stack()
    rpn_ind = 0
    i = 0

    while i < lenght:
        symbol = alg_primer[i]
        if symbol.isalpha():
            print("Ты где-то ввел текст")
            raise SystemExit(1)
        if isNum(symbol):
            while (isNum(symbol)):
                rpn_string += symbol
                if (i != lenght - 1):
                    i += 1
                    symbol = alg_primer[i]
                else:
                    symbol = None
                    i += 1
            rpn_string += " "
        else:
            if symbol == "-" and isSingleMinus(alg_primer, i):
                symbol = "~"
            if symbol == "(":
                rpn_stack.push(symbol)
            elif symbol == ")":
                while rpn_stack.get_top() != "(":
                    rpn_string += rpn_stack.pop()
                    rpn_string += " "
                rpn_stack.pop()
            else:
                priority = get_prinority(symbol)
                if rpn_stack.isEmpty() == 0:
                    rpn_stack.push(symbol)
                else:
                    priority_of_top = get_prinority(rpn_stack.get_top())
                    if (priority > priority_of_top):
                        rpn_stack.push(symbol)
                    else:
                        while (priority_of_top >= priority):
                            rpn_string += rpn_stack.pop()
                            rpn_string += " "
                            if rpn_stack.isEmpty() != 0:
                                priority_of_top = get_prinority(rpn_stack.get_top())
                            else:
                                priority_of_top = -1
                        rpn_stack.push(symbol)
            i += 1

    while rpn_stack.isEmpty() != 0:
        rpn_string += rpn_stack.pop()
        rpn_string += " "

    return rpn_string

