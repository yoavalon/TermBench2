def update_cells(state):
    new_state = [[0] * len(state[0]) for _ in range(len(state))]
    for i in range(len(state)):
        for j in range(len(state[0])):
            neighbors = sum((state[x][y] for x in range(max(0, i - 1), min(len(state), i + 2)) for y in range(max(0, j - 1), min(len(state[0]), j + 2)) if (x, y) != (i, j)))
            new_state[i][j] = 1 if neighbors == 3 or (neighbors == 2 and state[i][j]) else 0
    return new_state

def simulate(state):
    while True:
        state = update_cells(state)
        for row in state:
            print(''.join(('█' if cell else ' ' for cell in row)))
        print()

def main():
    initial_state = [[0, 0, 0, 0, 0], [0, 1, 1, 1, 0], [0, 0, 1, 0, 0], [0, 0, 1, 0, 0], [0, 0, 0, 0, 0]]
    simulate(initial_state)
main()