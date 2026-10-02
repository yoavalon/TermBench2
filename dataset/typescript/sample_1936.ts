function decay_function(value: number, rate: number, precision: number): number {
    return Math.round(value * (1 - rate) * Math.pow(10, precision)) / Math.pow(10, precision);
}

function simulate_decay(initial_value: number, decay_rate: number, precision: number, steps: number): number[] {
    let values: number[] = [initial_value];
    for (let _ = 0; _ < steps; _++) {
        let current_value = values[values.length - 1];
        let new_value = decay_function(current_value, decay_rate, precision);
        values.push(new_value);
    }
    return values;
}

function main(): void {
    let initial_value = 1.0;
    let decay_rate = 0.1;
    let precision = 4;
    let steps = 10;
    let result = simulate_decay(initial_value, decay_rate, precision, steps);
    console.log(result);
}

if (require.main === module) {
    main();
}