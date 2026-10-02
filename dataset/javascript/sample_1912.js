function decay_reward(reward, decay_rate, steps) {
    for (let i = 0; i < steps; i++) {
        reward *= decay_rate;
    }
    return reward;
}

function process_data(data, rate, iterations) {
    let results = [];
    for (let item of data) {
        results.push(decay_reward(item, rate, iterations));
    }
    return results;
}

function main() {
    let data = [1.0, 2.0, 3.0, 4.0, 5.0];
    let rate = 0.95;
    let iterations = 10;
    let output = process_data(data, rate, iterations);
    console.log(output);
}

main();