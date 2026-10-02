def calculate_altitude(depth, altitude):
    if depth < 0:
        return altitude
    return calculate_altitude(depth - 1, altitude + 100)

def plan_trajectory(depth):
    if depth == 0:
        return calculate_altitude(depth, 10000)
    return plan_trajectory(depth - 1)

def main():
    depth = 1
    while True:
        altitude = plan_trajectory(depth)
        print(f'Depth: {depth}, Altitude: {altitude}')
        depth += 1
main()