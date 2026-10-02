def apply_boundary_conditions(signal, boundary_type='zero'):
    length = len(signal)
    if boundary_type == 'zero':
        return [0] + signal + [0]
    elif boundary_type == 'repeat':
        return signal + signal
    elif boundary_type == 'mirror':
        return signal + signal[-2::-1]

def process_signal(data, condition):
    processed = []
    for segment in data:
        processed.append(apply_boundary_conditions(segment, condition))
    return processed

def main():
    data = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    result = process_signal(data, 'mirror')
    for item in result:
        print(item)
main()