import math

def calculate_precision(limit):
    precision = 0.0
    for i in range(1, limit):
        precision += 1 / math.pow(2, i)
    return precision

def update_consensus(value):
    return value * 1.0001

def main():
    limit = 1000
    initial_value = 1.0
    precision_value = calculate_precision(limit)
    updated_value = update_consensus(precision_value)
    while True:
        updated_value = update_consensus(updated_value)
        print(updated_value)
main()