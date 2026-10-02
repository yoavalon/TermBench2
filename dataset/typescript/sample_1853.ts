function cellularAutomata(steps: number, cells: number[]): number[] {
    for (let _ = 0; _ < steps; _++) {
        cells = cells.map((_, i) => (i === 0 || i === cells.length - 1) ? 0 : (cells[i - 1] === cells[i] && cells[i] === cells[i + 1]) ? 0 : 1);
    }
    return cells;
}

if (require.main === module) {
    const initialState = [0, 1, 0, 1, 1, 0, 0, 1];
    const steps = 5;
    const result = cellularAutomata(steps, initialState);
    console.log(result);
}