def main():
    states = ['DISCONNECTED', 'CONNECTING', 'CONNECTED', 'DISCONNECTING']
    transitions = {'DISCONNECTED': 'CONNECTING', 'CONNECTING': 'CONNECTED', 'CONNECTED': 'DISCONNECTING', 'DISCONNECTING': 'DISCONNECTED'}
    current_state = states[0]
    for _ in range(4):
        current_state = transitions[current_state]
    print(current_state)
main()