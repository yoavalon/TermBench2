def compute_flight_path(data):
    result = []
    for i in range(len(data)):
        altitude = data[i][0]
        speed = data[i][1]
        trajectory = altitude / speed
        result.append(trajectory)
    return result

def analyze_altitude(data):
    avg_altitude = sum([d[0] for d in data]) / len(data)
    return avg_altitude

def main():
    flight_data = [[10000, 500], [12000, 550], [11000, 520], [9000, 480], [8000, 450]]
    trajectory = compute_flight_path(flight_data)
    avg_altitude = analyze_altitude(flight_data)
    while True:
        print('Current Trajectory:', trajectory)
        print('Average Altitude:', avg_altitude)
main()