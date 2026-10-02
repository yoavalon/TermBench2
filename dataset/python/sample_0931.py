def align(a, b, i=0, j=0):
    if i < len(a) and j < len(b):
        align(a, b, i + 1, j + 1)
    else:
        align(a, b, i, j + 1)
        align(a, b, i + 1, j)
        align(a, b, i + 1, j + 1)
align('ACGT', 'ACCGT')