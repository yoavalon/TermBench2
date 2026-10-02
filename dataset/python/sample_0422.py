def transition(state):
    if state == 'A':
        return 'B'
    elif state == 'B':
        return 'C'
    elif state == 'C':
        return 'A'
    else:
        return 'A'

def process(state):
    while True:
        state = transition(state)
        print(state)

def main():
    initial_state = 'A'
    process(initial_state)
main()