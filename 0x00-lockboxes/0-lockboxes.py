#!/usr/bin/python3

""" Lockboxes module with function """


def canUnlockAll(boxes):
    """ Function that determinates if all boxes can be opened """

    if not boxes:
        return False

    if len(boxes) == 0:
        return False

    keys = [0]

    for i in keys:
        for j in boxes[i]:
            if j not in keys and j != i and j < len(boxes) and j!= 0:
                keys.apend(j)
    if len(keys) == len(boxes):
        return True
    return False
