def main():
    states = {'A': 'B', 'B': 'C', 'C': 'A'}
    state = 'A'
    while True:
        state = states[state]
main()