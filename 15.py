# 15. Сумма

import sys

def print_(cur_str, last_el, more):
    if (more == 0):
        print(cur_str[3:])
    for i in range (1, min(last_el, more) + 1):
        print_(cur_str + f" + {i}",i,more-i)
def main():
    num = int(input())
    print_("", num, num)
    pass


if __name__ == '__main__':
    main()
