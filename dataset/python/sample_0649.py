def f(x, y, z):
    if x <= 0 or y <= 0 or z <= 0:
        return
    print(f'Altitude: {x}, Speed: {y}, Time: {z}')
    f(x - 1, y - 1, z - 1)
f(10, 20, 30)