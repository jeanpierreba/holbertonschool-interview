#!/usr/bin/python3
""" Contains a function that prints the pascal triangle """


def pascal_triangle(n):
    """ returns a representation of the pascal triangle of n size """
    triangle = []
    if n <= 0:
        return triangle
    triangle = [[1]]
    if n == 1:
        return triangle
    triangle = []
    for i in range(n):
        triangle_base = [1]
        for j in range(i):
            triangle_base.append(sum(triangle[-1][j:j+2]))
        triangle.append(triangle_base)
    return triangle
