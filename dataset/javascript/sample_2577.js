function update_grid(grid, rule) {
    let size = grid.length;
    let new_grid = new Array(size).fill(0);
    for (let i = 0; i < size; i++) {
        let left = grid[(i - 1 + size) % size];
        let right = grid[(i + 1) % size];
        new_grid[i] = rule(left, grid[i], right);
    }
    return new_grid;
}

function cellular_automaton(steps, initial_state, rule) {
    let current_state = initial_state;
    for (let _ = 0; _ < steps; _++) {
        current_state = update_grid(current_state, rule);
    }
    return current_state;
}

function rule_conway(left, center, right) {
    let neighbor_count = left + center + right;
    if (center == 1) {
        return neighbor_count === 2 || neighbor_count === 3 ? 1 : 0;
    } else {
        return neighbor_count === 3 ? 1 : 0;
    }
}

function main() {
    let initial_state = [0, 1, 0, 1, 1, 0, 1, 0];
    let steps = 5;
    let final_state = cellular_automaton(steps, initial_state, rule_conway);
    console.log(final_state);
}

main();