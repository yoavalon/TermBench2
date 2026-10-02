def simulate_flight():
    x, y = (0, 0)
    dx, dy = (5, 2)
    while True:
        x += dx
        y += dy
        if y > 100:
            dy = -dy
        if x > 500:
            dx = -dx
        print(f'Position: ({x}, {y})')
simulate_flight()