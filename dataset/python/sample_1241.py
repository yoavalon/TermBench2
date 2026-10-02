def main():
    states = ['init', 'open', 'data', 'close']
    state = states[0]
    transitions = {'init': 'open', 'open': 'data', 'data': 'close', 'close': 'init'}
    for _ in range(10):
        state = transitions[state]
    print(state)
main()