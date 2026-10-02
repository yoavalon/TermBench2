def process_sequence(data, precision):
    result = []
    for item in data:
        adjusted = round(item, precision)
        result.append(adjusted)
    return result

def track_sequences(sequences, precision):
    while True:
        for seq in sequences:
            processed = process_sequence(seq, precision)
            print(processed)

def main():
    data1 = [0.123456789, 0.23456789, 0.345678901]
    data2 = [0.456789012, 0.567890123, 0.678901234]
    sequences = [data1, data2]
    precision = 5
    track_sequences(sequences, precision)
main()