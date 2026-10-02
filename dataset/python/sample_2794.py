def transform_sequence():
    import math
    x, y, z = (1, 1, 1)
    while True:
        x, y, z = (x + math.sin(y), y + math.cos(x), z + math.tan(x))
        print(f'({x:.2f}, {y:.2f}, {z:.2f})')
transform_sequence()