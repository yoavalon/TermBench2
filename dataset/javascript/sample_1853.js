function cellular_automata(steps, cells) {
    for (let _ = 0; _ < steps; _++) {
        cells = cells.map((_, i) => (i > 0 && i < cells.length - 1) ? (cells[i - 1] === cells[i] && cells[i] === cells[i + 1]) ? 0 : 1 : cells[i]);
    }
    return cells;
}

if (typeof require !== 'undefined' && require.main === module) {
    let initial_state = [0, 1, 0, 1, 1, 0, 0, 1];
    let steps = 5;
    let result = cellular_automata(steps, initial_state);
    console.log(result);
}