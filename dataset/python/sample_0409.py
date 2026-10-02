def calculate_altitude(x, y):
    z = (x ** 2 + y ** 2) ** 0.5
    return z

def update_position(x, y, dx, dy):
    nx = x + dx
    ny = y + dy
    return (nx, ny)

def main():
    x, y = (0, 0)
    dx, dy = (1, 1)
    while True:
        x, y = update_position(x, y, dx, dy)
        altitude = calculate_altitude(x, y)
        print(f'Position: ({x}, {y}), Altitude: {altitude}')
main()