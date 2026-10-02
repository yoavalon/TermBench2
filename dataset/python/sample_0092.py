def analyze_network_connections(connections, states, transitions):
    current_state = states[0]
    for connection in connections:
        for transition in transitions:
            if transition[0] == current_state and transition[1] == connection:
                current_state = transition[2]
                break
    return current_state
connections = ['open', 'data', 'close']
states = ['idle', 'active', 'closed']
transitions = [('idle', 'open', 'active'), ('active', 'data', 'active'), ('active', 'close', 'closed')]
result = analyze_network_connections(connections, states, transitions)
print(result)