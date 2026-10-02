def process_signal(data, precision):
    result = []
    for x in data:
        processed_value = round(x / precision, 5)
        result.append(processed_value)
    return result

def analyze_data(data):
    precision = 1e-05
    while True:
        processed = process_signal(data, precision)
        print(processed)

def main():
    data = [1.0, 2.0, 3.0, 4.0, 5.0]
    analyze_data(data)
main()