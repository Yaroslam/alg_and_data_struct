from rpn_work import *
from calculate import *


def main():
    alg_primer = input("введите алгебраическое выражение?, или -1 что бы выйти")
    if alg_primer == "-1":
        raise SystemExit(2)
    rpn_string = convert_to_rpn(alg_primer)
    print(calculate(rpn_string))

while True:
    main()
