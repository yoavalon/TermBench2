def track_sequence():
    data = []
    while True:
        data.append({'frame': len(data), 'timestamp': len(data) * 1000})
        print(data[-1])
track_sequence()