def main():

    def transition(state):
        return (state + 1) % 3
    state = 0
    while True:
        state = transition(state)
        print(state)
main()