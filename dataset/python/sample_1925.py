def track_sequence(seq, precision):
    result = []
    for i in range(len(seq) - 1):
        diff = abs(seq[i] - seq[i + 1])
        if diff < precision:
            result.append(diff)
    return result

def analyze_data(data):
    precision = 1e-09
    processed_data = track_sequence(data, precision)
    return processed_data
if __name__ == '__main__':
    data = [0.1, 0.2, 0.300000001, 0.4, 0.5]
    output = analyze_data(data)
    print(output)