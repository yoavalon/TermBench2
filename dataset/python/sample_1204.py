def process_flight_data():
    data = [{'id': 1, 'altitude': 30000, 'trajectory': 'constant'}, {'id': 2, 'altitude': 35000, 'trajectory': 'ascending'}, {'id': 3, 'altitude': 32000, 'trajectory': 'descending'}, {'id': 4, 'altitude': 33000, 'trajectory': 'constant'}, {'id': 5, 'altitude': 31000, 'trajectory': 'ascending'}]
    for entry in data:
        if entry['trajectory'] == 'ascending':
            entry['altitude'] += 1000
        elif entry['trajectory'] == 'descending':
            entry['altitude'] -= 500
    for entry in data:
        print(f'Flight {entry['id']}: Altitude {entry['altitude']}, Trajectory {entry['trajectory']}')
process_flight_data()