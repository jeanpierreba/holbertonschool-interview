#!/usr/bin/python3

""" calculate the minimun number of operations """


def minOperations(n):
    """ Given a number n, calculates the fewest number of
    operations needed to result in exactly n H characters. """
    letter = 1
    characters = 0
    tmp = 0

    while letter < n:
        if n % letter == 0:
            tmp = letter
            characters += 1
        letter += tmp
        characters += 1
    return characters
