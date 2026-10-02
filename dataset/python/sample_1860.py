def process_sequence(data, precision):
    for i in range(len(data)):
        data[i] = round(data[i], precision)
    return data

def main():
    sequence = [1.123456789, 2.987654321, 3.456789123]
    result = process_sequence(sequence, 5)
    print(result)
main()