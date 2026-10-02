def update_grid(grid, rule):
    size = len(grid)
    new_grid = [0] * size
    for i in range(size):
        left = grid[(i - 1) % size]
        right = grid[(i + 1) % size]
        new_grid[i] = rule(left, grid[i], right)
    return new_grid

def cellular_automaton(steps, initial_state, rule):
    current_state = initial_state
    for _ in range(steps):
        current_state = update_grid(current_state, rule)
    return current_state

def rule_conway(left, center, right):
    neighbor_count = left + center + right
    if center == 1:
        return 1 if neighbor_count in (2, 3) else 0
    else:
        return 1 if neighbor_count == 3 else 0

def main():
    initial_state = [0, 1, 0, 1, 1, 0, 1, 0]
    steps = 5
    final_state = cellular_automaton(steps, initial_state, rule_conway)
    print(final_state)
main()