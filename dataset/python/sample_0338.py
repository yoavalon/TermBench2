def flight_planner():
    x, y, z = (0, 0, 0)
    while True:
        x += 1
        y += 2
        z += 3
        print(f'Trajectory: x={x}, y={y}, z={z}')
flight_planner()