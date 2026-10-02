def generate_flight_path():
    while True:
        altitude = 35000
        path = [(0, altitude)]
        for i in range(1, 100):
            altitude += i % 2 * 1000 - 500
            path.append((i, altitude))
        yield path

def display_trajectory():
    for path in generate_flight_path():
        for step in path:
            print(f'Step {step[0]}: Altitude {step[1]} meters')
        print('End of trajectory')

def main():
    display_trajectory()
main()