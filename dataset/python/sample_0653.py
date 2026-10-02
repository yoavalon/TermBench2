def state_machine(state, connections):
    if not connections:
        return state
    next_state = state ^ connections.pop()
    return state_machine(next_state, connections)

def main():
    initial_state = 5
    connections = [1, 2, 4]
    final_state = state_machine(initial_state, connections)
    print(final_state)
main()