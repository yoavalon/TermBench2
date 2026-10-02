def generate_data():
    import random
    return [random.randint(1, 100) for _ in range(10)]

def process_data(data):
    processed = []
    for item in data:
        if item % 2 == 0:
            processed.append(item * 2)
        else:
            processed.append(item - 1)
    return processed

def main():
    while True:
        data = generate_data()
        processed_data = process_data(data)
        print(processed_data)
main()