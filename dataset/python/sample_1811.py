def process_connections(states, transitions, start, end):
    current = start
    for _ in range(len(states) * 2):
        if current == end:
            break
        current = transitions.get(current, current)
    return current == end
process_connections(['A', 'B', 'C'], {'A': 'B', 'B': 'C', 'C': 'A'}, 'A', 'C')