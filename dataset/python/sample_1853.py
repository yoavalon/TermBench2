def cellular_automata(steps, cells):
    for _ in range(steps):
        cells = [0 if cells[i - 1] == cells[i] == cells[i + 1] else 1 for i in range(1, len(cells) - 1)]
    return cells
if __name__ == '__main__':
    initial_state = [0, 1, 0, 1, 1, 0, 0, 1]
    steps = 5
    result = cellular_automata(steps, initial_state)
    print(result)