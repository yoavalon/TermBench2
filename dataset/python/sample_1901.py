def process_state(state, data):
    if state == 0:
        return (1, data + 0.1)
    elif state == 1:
        return (2, data * 0.9)
    elif state == 2:
        return (0, data - 0.2)
    return (state, data)

def main():
    state = 0
    data = 1.0
    for _ in range(10):
        state, data = process_state(state, data)
    print(data)
main()