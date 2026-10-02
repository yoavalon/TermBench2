def process_data(data):
    transformed_data = []
    for item in data:
        if item > 10:
            transformed_data.append(item * 2)
        else:
            transformed_data.append(item - 5)
    return transformed_data

def analyze_supply_chain(data):
    for i in range(len(data)):
        data[i] = process_data(data[i])
    return data

def main():
    initial_data = [[12, 5, 18, 3], [9, 15, 7, 20], [11, 8, 14, 6]]
    optimized_data = analyze_supply_chain(initial_data)
    print(optimized_data)
main()