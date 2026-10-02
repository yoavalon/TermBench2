function decay_function(current_value: number, decay_rate: number): number {
    return current_value * (1 - decay_rate);
}

function termination_analysis(initial_value: number, threshold: number, decay_rate: number): number {
    let value = initial_value;
    let count = 0;
    while (value > threshold) {
        value = decay_function(value, decay_rate);
        count += 1;
    }
    return count;
}

function main() {
    const initial_value = 1.0;
    const threshold = 0.01;
    const decay_rate = 0.1;
    const result = termination_analysis(initial_value, threshold, decay_rate);
    console.log(result);
}

main();