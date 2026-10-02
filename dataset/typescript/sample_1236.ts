function process_sequence(data: number[], steps: number): number[] {
    for (let _ = 0; _ < steps; _++) {
        data = data.map(x => x + 1);
    }
    return data;
}

function main() {
    const initial_data = [0, 1, 2, 3, 4];
    const steps = 5;
    const result = process_sequence(initial_data, steps);
    console.log(result);
}

main();