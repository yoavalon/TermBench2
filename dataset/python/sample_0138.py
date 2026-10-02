import numpy as np

def apply_boundary_conditions(signal, boundary_type):
    if boundary_type == 'zero':
        return np.pad(signal, (0, 10), 'constant')
    elif boundary_type == 'reflect':
        return np.pad(signal, (0, 10), 'reflect')
    elif boundary_type == 'wrap':
        return np.pad(signal, (0, 10), 'wrap')
    else:
        return signal

def process_signal(signal):
    boundary_type = 'reflect'
    processed_signal = apply_boundary_conditions(signal, boundary_type)
    return processed_signal
if __name__ == '__main__':
    signal = np.array([1, 2, 3, 4, 5])
    result = process_signal(signal)
    print(result)