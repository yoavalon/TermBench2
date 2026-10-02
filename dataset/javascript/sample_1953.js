function decay_function(current_value, decay_rate) {
    return current_value * (1 - decay_rate);
}

function termination_analysis(initial_value, threshold, decay_rate) {
    let value = initial_value;
    let count = 0;
    while (value > threshold) {
        value = decay_function(value, decay_rate);
        count += 1;
    }
    return count;
}

function main() {
    let initial_value = 1.0;
    let threshold = 0.01;
    let decay_rate = 0.1;
    let result = termination_analysis(initial_value, threshold, decay_rate);
    console.log(result);
}

main();