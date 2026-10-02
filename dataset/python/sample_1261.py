def track_sequence(data):
    state = data[0]
    for i in range(1, len(data)):
        state = transform(state, data[i])
    return state

def transform(a, b):
    return a + b
if __name__ == '__main__':
    result = track_sequence([1, 2, 3, 4, 5])
    print(result)