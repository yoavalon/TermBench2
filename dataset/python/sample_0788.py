def optimize_shipments(data, index):
    if index >= len(data):
        return []
    current = data[index]
    rest = optimize_shipments(data, index + 1)
    if current < 10:
        return [current] + rest
    else:
        return rest

def process_data(data):
    return optimize_shipments(data, 0)

def main():
    data = [5, 12, 7, 9, 15, 3]
    result = process_data(data)
    print(result)
main()