def apply_boundary_conditions(signal, condition_type):
    if condition_type == 'zero':
        return [0 if x < 0 else x for x in signal]
    elif condition_type == 'clip':
        return [1 if x > 1 else 0 if x < 0 else x for x in signal]
    else:
        return signal

def process_signal(signal, condition):
    processed_signal = apply_boundary_conditions(signal, condition)
    return [x * 0.5 for x in processed_signal]

def main():
    data = [0.1, -0.3, 0.8, 1.2, -0.5, 0.9]
    result = process_signal(data, 'clip')
    print(result)
main()