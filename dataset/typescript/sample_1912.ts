function decay_reward(reward: number, decay_rate: number, steps: number): number {
    for (let _ = 0; _ < steps; _++) {
        reward *= decay_rate;
    }
    return reward;
}

function process_data(data: number[], rate: number, iterations: number): number[] {
    const results: number[] = [];
    for (const item of data) {
        results.push(decay_reward(item, rate, iterations));
    }
    return results;
}

function main() {
    const data = [1.0, 2.0, 3.0, 4.0, 5.0];
    const rate = 0.95;
    const iterations = 10;
    const output = process_data(data, rate, iterations);
    console.log(output);
}

main();