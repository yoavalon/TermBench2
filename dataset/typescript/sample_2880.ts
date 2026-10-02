function* simulate_temp_change(initial_temp: number, rate: number, time_step: number): Generator<number> {
    let current_temp = initial_temp;
    while (true) {
        current_temp += rate * time_step;
        yield current_temp;
    }
}

function analyze_sequence(sequence: Generator<number>): void {
    for (const value of sequence) {
        console.log(`Current Temperature: ${value.toFixed(2)}K`);
    }
}

function main(): void {
    const initial_temp = 300;
    const rate = 0.01;
    const time_step = 1;
    const sequence = simulate_temp_change(initial_temp, rate, time_step);
    analyze_sequence(sequence);
}

main();