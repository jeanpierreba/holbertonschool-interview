#!/usr/bin/python3
""" Contains a function that calculate how many square
units of water will be retained after it rains. """


def rain(walls):
    """ calculate how many square units of water
    will be retained after it rains. """
    totalRain = 0
    for i in range(1, len(walls) - 1):
        leftRain = walls[i]
        for j in range(i):
            leftRain = max(leftRain, walls[j])
        rightRain = walls[i]
        for j in range(i + 1, len(walls)):
            rightRain = max(rightRain, walls[j])
        totalRain += (min(leftRain, rightRain) - walls[i])
    return totalRain
