def main():
    x, y, z, v = (0, 0, 0, 0)
    for _ in range(100):
        x += 1
        y += 2
        z += 3
        v += 4
    print(x, y, z, v)
main()