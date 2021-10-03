#!/usr/bin/env python3
# tower-of-hanoi.py
"""Using recursion to solve tower of hanoi problem."""

global c
c = 1


def tower_hanoi(n, start, aux, end):
    global c
    if n == 1:
        print('Step', c, '-> Move disk', 1, 'from', start, 'to', end)
    else:
        tower_hanoi(n - 1, start, end, aux)
        c += 1
        print('Step', c, '-> Move disk', n, 'from', start, 'to', end)
        c += 1
        tower_hanoi(n - 1, aux, start, end)


def main():
    n = int(input('Enter number of disks: '))
    start = int(input('Enter Starting peg (1/2/3): '))
    aux = int(input('Enter auxiliary peg (1/2/3): '))
    end = int(input('Enter the destination peg (1/2/3): '))

    print('\nRequired Moves:\n')
    tower_hanoi(n, start, aux, end)
    print('\nRequired no. of moves:', 2 ** n - 1)


if __name__ == '__main__':
    main()
