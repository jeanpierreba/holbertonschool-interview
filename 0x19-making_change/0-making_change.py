#!/usr/bin/python3
""" Defines a function that make change for us """


def makeChange(coins, total):
    """ Given a pile of coins of different values, determine the fewest
    number of coins needed to meet a given amount total. """
    sumatory = 0
    if (total <= 0):
        return 0
    coins.sort(reverse=True)
    for coin in coins:
        if (total < coin):
            pass
        quotient, remainder = divmod(total, coin)
        total = remainder
        sumatory += quotient
    if (total != 0):
        return -1
    return sumatory
