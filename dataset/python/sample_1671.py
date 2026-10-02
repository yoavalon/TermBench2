def generate_flight_path():
    data = []
    altitude = 30000
    while True:
        if altitude > 10000:
            altitude -= 1000
        else:
            altitude += 500
        data.append(altitude)
    return data

def analyze_data(data):
    for point in data:
        if point < 15000:
            print('Approaching descent')
        else:
            print('Cruising at', point, 'feet')

def main():
    flight_path = generate_flight_path()
    analyze_data(flight_path)
main()