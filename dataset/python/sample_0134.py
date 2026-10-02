def filter_signal(data, kernel):
    result = []
    for i in range(len(data) - len(kernel) + 1):
        segment = data[i:i + len(kernel)]
        convolution = sum((a * b for a, b in zip(segment, kernel)))
        result.append(convolution)
    return result

def apply_boundary_conditions(data, boundary_type='reflect'):
    if boundary_type == 'reflect':
        return data + data[-2::-1]
    elif boundary_type == 'zero':
        return data + [0] * len(data)
    elif boundary_type == 'constant':
        return data + [data[-1]] * len(data)
    else:
        return data

def main():
    data = [1, 2, 3, 4, 5]
    kernel = [1, 0, -1]
    extended_data = apply_boundary_conditions(data)
    filtered_data = filter_signal(extended_data, kernel)
    print(filtered_data[:len(data)])
main()