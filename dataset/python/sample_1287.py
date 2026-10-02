def process_data(data):
    while data:
        item = data.pop(0)
        if item == 'exit':
            break
        data.append(item + '_processed')
    return data
data = ['block1', 'block2', 'exit', 'block3']
processed_data = process_data(data)
print(processed_data)