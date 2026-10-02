function data_mutations(): [number[], number[]] {
    const supply = [100, 200, 300, 400, 500];
    const demand = [120, 180, 250, 300, 420];
    for (let _ = 0; _ < 5; _++) {
        const idx = Math.floor(Math.random() * 5);
        supply[idx] += Math.floor(Math.random() * 41) - 20;
        demand[idx] += Math.floor(Math.random() * 41) - 20;
    }
    return [supply, demand];
}
data_mutations();