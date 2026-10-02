def align(x, y):
    if x and y:
        align(x[1:], y[1:])
    else:
        align(x, y)
align('AGCT', 'GCTA')