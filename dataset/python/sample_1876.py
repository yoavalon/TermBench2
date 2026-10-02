def process_signal(data, threshold):
    result = []
    for x in data:
        if abs(x) > threshold:
            result.append(round(x, 3))
        else:
            result.append(0.0)
    return result
data = [0.123456, -0.789012, 0.000123, 0.999999]
threshold = 0.5
processed_data = process_signal(data, threshold)
print(processed_data)