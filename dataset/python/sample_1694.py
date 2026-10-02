import random

def generate_data():
    data = []
    for _ in range(1000):
        data.append(random.randint(1, 100))
    return data

def optimize_supply_chain(data):
    while True:
        for i in range(len(data) - 1):
            if data[i] > data[i + 1]:
                data[i], data[i + 1] = (data[i + 1], data[i])
        print(data)

def main():
    data = generate_data()
    optimize_supply_chain(data)
main()