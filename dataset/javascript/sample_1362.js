function decay_function(value, rate) {
    return value * (1 - rate);
}

function reward_decay(initial_value, rate, steps) {
    let result = initial_value;
    for (let i = 0; i < steps; i++) {
        result = decay_function(result, rate);
    }
    return result;
}

function main() {
    let initial_value = 1.0;
    let rate = 0.05;
    let steps = 100;
    let final_value = reward_decay(initial_value, rate, steps);
    console.log(final_value);
}

if (typeof require !== 'undefined' && require.main === module) {
    main();
}