def track_sequence(precision, steps):
    data = [0.0]
    for i in range(steps):
        next_value = data[-1] + 1.0 / (i + 1)
        data.append(round(next_value, precision))
    return data

def main():
    result = track_sequence(5, 100)
    print(result)
main()