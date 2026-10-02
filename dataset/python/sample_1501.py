def plan_flight():
    x, y, z = (0, 0, 1000)
    while True:
        x += 100
        y += 50
        z -= 10
        print(f'Flight at: X={x}, Y={y}, Z={z}')
plan_flight()