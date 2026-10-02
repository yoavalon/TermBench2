def track_sequences(data):
    while True:
        for item in data:
            print(item)
        data.append(data[-1] + 1)
track_sequences([1, 2, 3])