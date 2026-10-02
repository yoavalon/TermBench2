function simulate_decay(steps, decay_rate, initial_value) {
    let value = initial_value;
    let results = [];
    for (let i = 0; i < steps; i++) {
        results.push(value);
        value *= decay_rate;
    }
    return results;
}

function main() {
    let steps = 10;
    let decay_rate = 0.9;
    let initial_value = 100;
    let result = simulate_decay(steps, decay_rate, initial_value);
    console.log(result);
}
main();