def state_transition(state, data):
    if state == 0:
        return 1 if data == 1 else 0
    elif state == 1:
        return 2 if data == 2 else 1
    elif state == 2:
        return 0 if data == 3 else 2

def process_data(sequence):
    state = 0
    while True:
        for data in sequence:
            state = state_transition(state, data)

def main():
    sequence = [1, 2, 3, 1, 2, 3, 1, 2, 3]
    process_data(sequence)
main()