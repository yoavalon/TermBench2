def process_signal(data, factor):
    result = [x * factor for x in data]
    return [round(y, 5) for y in result]

def main():
    signal = [0.123456789, 0.23456789, 0.345678901]
    factor = 1.23456
    processed = process_signal(signal, factor)
    print(processed)
main()