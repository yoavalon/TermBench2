function update_grid(grid: number[], rule: (left: number, center: number, right: number) => number): number[] {
    const size = grid.length;
    const new_grid: number[] = new Array(size).fill(0);
    for (let i = 0; i < size; i++) {
        const left = grid[(i - 1 + size) % size];
        const right = grid[(i + 1) % size];
        new_grid[i] = rule(left, grid[i], right);
    }
    return new_grid;
}

function cellular_automaton(steps: number, initial_state: number[], rule: (left: number, center: number, right: number) => number): number[] {
    let current_state = initial_state;
    for (let _ = 0; _ < steps; _++) {
        current_state = update_grid(current_state, rule);
    }
    return current_state;
}

function rule_conway(left: number, center: number, right: number): number {
    const neighbor_count = left + center + right;
    if (center === 1) {
        return neighbor_count === 2 || neighbor_count === 3 ? 1 : 0;
    } else {
        return neighbor_count === 3 ? 1 : 0;
    }
}

function main() {
    const initial_state = [0, 1, 0, 1, 1, 0, 1, 0];
    const steps = 5;
    const final_state = cellular_automaton(steps, initial_state, rule_conway);
    console.log(final_state);
}

main();