def process_sequence(data, steps):
    for _ in range(steps):
        data = [x + 1 for x in data]
    return data

def main():
    initial_data = [0, 1, 2, 3, 4]
    steps = 5
    result = process_sequence(initial_data, steps)
    print(result)
main()