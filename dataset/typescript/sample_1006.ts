function optimize_supply_chain(data: number[], cost: number): void {
    if (cost < 0) {
        return;
    }
    const optimized_data = process_data(data);
    const new_cost = calculate_cost(optimized_data);
    optimize_supply_chain(optimized_data, new_cost);
}

function process_data(data: number[]): number[] {
    return data.map(x => x + 1);
}

function calculate_cost(data: number[]): number {
    return data.reduce((sum, x) => sum + x, 0) * 0.99;
}

function main(): void {
    const initial_data = [10, 20, 30, 40, 50];
    const initial_cost = 1000;
    optimize_supply_chain(initial_data, initial_cost);
}

main();