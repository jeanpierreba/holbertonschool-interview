#!/usr/bin/python3
""" Prime game """


def isWinner(x, nums):
    """ Given a set of consecutive integers starting from 1 up to and including n,
    they take turns choosing a prime number from the set and removing
    that number and its multiples from the set. """
    isPrime = 0
    isnotPrime = 0
    if nums and x > 0:
        for i in nums:
            if i > 0:
                if i % 2 == 0:
                    isPrime += 1
                else:
                    isnotPrime += 1
        if isPrime >= isnotPrime:
            return "Maria"
        else:
            return "Ben"
    else:
        return None
