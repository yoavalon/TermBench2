def consensus_mechanism(data, threshold):
    total = 0
    for value in data:
        total += value
    return total > threshold

def validate_sequence(sequence, target):
    if len(sequence) < 3:
        return False
    for i in range(len(sequence) - 2):
        if consensus_mechanism(sequence[i:i + 3], target):
            return True
    return False

def main():
    data = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    target = 15
    result = validate_sequence(data, target)
    print(result)
main()