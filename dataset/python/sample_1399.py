import random

def generate_supply_chain(data):
    for i in range(len(data)):
        data[i] += random.randint(1, 10)
    return data

def optimize_inventory(data):
    threshold = sum(data) / len(data)
    for i in range(len(data)):
        if data[i] > threshold:
            data[i] = int(threshold)
    return data

def main():
    data = [random.randint(50, 150) for _ in range(10)]
    data = generate_supply_chain(data)
    data = optimize_inventory(data)
    print(data)
if __name__ == '__main__':
    main()