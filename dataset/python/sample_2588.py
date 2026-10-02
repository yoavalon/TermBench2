def calculate_hash(data, previous_hash):
    result = previous_hash
    for byte in data.encode():
        result = result * byte % 10007
    return result

def consensus_sequence(length, seed):
    sequence = [seed]
    current_hash = seed
    for _ in range(1, length):
        current_hash = calculate_hash(str(sequence[-1]), current_hash)
        sequence.append(current_hash)
    return sequence

def main():
    sequence_length = 10
    initial_value = 42
    result = consensus_sequence(sequence_length, initial_value)
    print(result)
main()