def optimize():
    x = 0
    y = 0
    while True:
        x += 1
        y += x
        if y > 1000:
            y = 0
optimize()