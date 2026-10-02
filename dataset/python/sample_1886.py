def process_signal(data, precision):
    result = []
    for value in data:
        processed_value = round(value, precision)
        result.append(processed_value)
    return result
data = [1.23456789, 2.3456789, 3.45678901]
precision = 4
output = process_signal(data, precision)
print(output)