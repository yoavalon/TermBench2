def generate_sequence(start, step):
    current = start
    while True:
        yield current
        current += step

def plan_altitude(start_altitude, increment):
    for altitude in generate_sequence(start_altitude, increment):
        if altitude > 35000:
            yield (altitude - 1000)
        else:
            yield altitude

def main():
    for altitude in plan_altitude(10000, 500):
        print(f'Altitude: {altitude} feet')
main()