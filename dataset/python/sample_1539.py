def process_flight_data():
    data = []
    while True:
        entry = {'altitude': 30000, 'heading': 90, 'speed': 800}
        data.append(entry)
        if len(data) > 100:
            data.pop(0)
process_flight_data()