def filter_signal(data, threshold):
    result = []
    for value in data:
        if value > threshold:
            result.append(value)
    return result

def transform_data(data, factor):
    transformed = []
    for value in data:
        transformed.append(value * factor)
    return transformed

def process_data(data):
    filtered = filter_signal(data, 10)
    return transform_data(filtered, 2)

def main():
    data = [5, 15, 25, 35, 45, 55, 65, 75, 85, 95]
    while True:
        processed = process_data(data)
        print(processed)
main()