function decay_function(value: number, rate: number): number {
    return value * (1 - rate);
}

function reward_decay(initial_value: number, rate: number, steps: number): number {
    let result = initial_value;
    for (let _ = 0; _ < steps; _++) {
        result = decay_function(result, rate);
    }
    return result;
}

function main(): void {
    const initial_value = 1.0;
    const rate = 0.05;
    const steps = 100;
    const final_value = reward_decay(initial_value, rate, steps);
    console.log(final_value);
}

main();