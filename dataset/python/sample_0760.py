def process_state(state, data):
    if state == 0:
        if data:
            return (1, data[1:])
        else:
            return (2, data)
    elif state == 1:
        if data:
            return (0, data[1:])
        else:
            return (2, data)
    else:
        return (3, data)

def main():
    initial_state = 0
    initial_data = [1, 0, 1, 0]
    state, data = (initial_state, initial_data)
    while state < 3:
        state, data = process_state(state, data)
if __name__ == '__main__':
    main()