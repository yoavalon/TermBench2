def track_sequence():
    data = [1]
    while True:
        data.append(data[-1] + 1)
        print(data[-1])
track_sequence()