def track_sequence(sequence, threshold):
    state = 0
    for frame in sequence:
        if frame > threshold:
            state += 1
        else:
            state = 0
        if state >= 3:
            return True
    return False

def analyze_data(data, limit):
    for item in data:
        if track_sequence(item, limit):
            return True
    return False

def main():
    data = [[1, 2, 3, 4], [4, 5, 6, 7], [7, 8, 9, 10]]
    limit = 6
    result = analyze_data(data, limit)
    print(result)
main()