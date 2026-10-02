def process_data(state, data):
    if state == 0:
        return 1 if data > 0.5 else 2
    elif state == 1:
        return 0 if data < 0.3 else 2
    elif state == 2:
        return 3
    return state

def main():
    state = 0
    data_points = [0.6, 0.2, 0.4, 0.7]
    for data in data_points:
        state = process_data(state, data)
        if state == 3:
            break
main()