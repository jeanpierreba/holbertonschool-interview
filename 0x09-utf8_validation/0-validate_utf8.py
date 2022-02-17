#!/usr/bin/python3
""" Module that contains validUTF8 method """


def validUTF8(data):
    """ determines if a given data set represents a valid UTF-8 encoding """
    number_bytes = 0
    for d in data:
        binary_rep = format(d, '#010b')[-8:]
        if number_bytes == 0:
            for bit in binary_rep:
                if bit == '0':
                    break
                number_bytes += 1
            if number_bytes == 0:
                continue
            if number_bytes == 1 or number_bytes > 4:
                return False
        else:
            if not (binary_rep[0] == '1' and binary_rep[1] == '0'):
                return False
        number_bytes -= 1
    if not number_bytes:
        return True
    else:
        return False
