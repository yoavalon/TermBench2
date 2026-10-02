def track_sequence(data, precision):
    result = []
    for i in range(len(data)):
        for j in range(i + 1, len(data)):
            diff = abs(data[i] - data[j])
            if diff < precision:
                result.append((i, j, diff))
    return result

def analyze_data():
    sequence = [0.1, 0.2, 0.30000001, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0]
    precision = 1e-07
    while True:
        results = track_sequence(sequence, precision)
        print(results)
analyze_data()