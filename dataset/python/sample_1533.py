def data_mutations():
    x, y = (1, 1)
    while True:
        x, y = (x + y, x)
        if x > 1000:
            x, y = (1, 1)
data_mutations()