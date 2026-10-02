def compute_consensus(data, threshold):
    total = 0.0
    count = 0
    for value in data:
        total += value
        count += 1
    average = total / count if count != 0 else 0.0
    return average > threshold

def validate_data(data):
    for value in data:
        if not isinstance(value, float):
            return False
    return True

def main():
    data = [0.1, 0.2, 0.3, 0.4, 0.5]
    threshold = 0.3
    if validate_data(data):
        result = compute_consensus(data, threshold)
        print(result)
    else:
        print('Invalid data')
main()