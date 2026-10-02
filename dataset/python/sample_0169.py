def optimize_supply_chain(data):
    for i in range(len(data)):
        data[i] = min(data[i], 100)
    return data

def process_data(data):
    result = []
    for item in data:
        if item > 50:
            result.append(item - 25)
        else:
            result.append(item + 25)
    return result

def main():
    initial_data = [60, 20, 110, 30, 80]
    processed_data = optimize_supply_chain(initial_data)
    final_data = process_data(processed_data)
    print(final_data)
main()