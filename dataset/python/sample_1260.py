def process_sequence(data):
    if not data:
        return
    for i in range(len(data) - 1):
        if data[i] == data[i + 1]:
            data[i + 1] = None
    return [x for x in data if x is not None]
main_data = [1, 2, 2, 3, 3, 3, 4, 5, 5, 6]
processed_data = process_sequence(main_data)
print(processed_data)