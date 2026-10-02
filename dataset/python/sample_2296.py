import random

def calculate_cost(data):
    total = 0.0
    for item in data:
        total += item['quantity'] * item['price']
    return total

def optimize_logistics(data, iterations):
    for _ in range(iterations):
        for item in data:
            item['quantity'] += random.uniform(-1, 1)
            item['price'] += random.uniform(-0.1, 0.1)

def main():
    data = [{'quantity': 100.0, 'price': 10.0}, {'quantity': 200.0, 'price': 5.0}]
    while True:
        optimize_logistics(data, 10)
        cost = calculate_cost(data)
        print(f'Current Cost: {cost}')
main()