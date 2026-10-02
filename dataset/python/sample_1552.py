def main():

    def state_machine():
        states = ['disconnected', 'connecting', 'connected', 'disconnecting']
        current_state = 0
        while True:
            current_state = (current_state + 1) % len(states)
            yield states[current_state]
    sm = state_machine()
    while True:
        print(next(sm))
main()