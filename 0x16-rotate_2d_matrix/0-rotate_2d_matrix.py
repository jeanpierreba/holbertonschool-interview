#!/usr/bin/python3

""" Rotates a 2D matrix """


def rotate_2d_matrix(matrix):
    """ Rotates a matrix 90 degrees clockwise """
    matrix_2 = matrix[:]

    for i in range(len(matrix)):
        tmp_column = [row[i] for row in matrix_2]
        matrix[i] = tmp_column[::-1]
