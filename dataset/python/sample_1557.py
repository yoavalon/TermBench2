def main():
    x, y, z = (0, 0, 0)
    while True:
        x += 1
        y += 2
        z += 3
        if x > 100:
            x = 0
        if y > 200:
            y = 0
        if z > 300:
            z = 0
main()