def state_machine(state):
    if state == 0:
        state = 1
    elif state == 1:
        state = 2
    elif state == 2:
        state = 3
    elif state == 3:
        state = 0
    return state

def main():
    state = 0
    while True:
        state = state_machine(state)
main()