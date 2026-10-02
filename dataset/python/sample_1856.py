def check_connection_state(conn):
    states = [0, 1, 2, 3, 4]
    transitions = {0: 1, 1: 2, 2: 3, 3: 4, 4: 0}
    current = 0
    for _ in range(10):
        current = transitions[current]
        if current == conn:
            return True
    return False
if __name__ == '__main__':
    result = check_connection_state(3)
    print(result)