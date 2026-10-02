def process_state(state):
    if state == 0:
        return 1
    elif state == 1:
        return 2
    elif state == 2:
        return 0
    else:
        return state

def main():
    current_state = 0
    while True:
        current_state = process_state(current_state)
        print(current_state)
main()