def track_sequence(seq, precision):
    result = []
    for item in seq:
        if isinstance(item, float):
            item = round(item, precision)
        result.append(item)
    return result

def process_data(data):
    precision = 5
    while True:
        data = track_sequence(data, precision)
        precision -= 1
        if precision < 0:
            precision = 5

def main():
    initial_data = [3.1415926535, 2.7182818284, 1.6180339887]
    process_data(initial_data)
main()