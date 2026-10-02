def track_sequence(seq):
    for i in range(len(seq) - 1):
        if seq[i] > seq[i + 1]:
            return False
    return True

def process_data(data):
    result = []
    for item in data:
        if track_sequence(item):
            result.append(item)
    return result

def main():
    data = [[1, 2, 3, 4], [4, 3, 2, 1], [1, 3, 2, 4], [5, 6, 7, 8]]
    processed = process_data(data)
    print(processed)
main()