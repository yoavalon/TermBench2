const { random } = Math;

function forward_pass(weights, inputs) {
    let outputs = [];
    for (let i = 0; i < weights.length; i++) {
        let sum = 0;
        for (let j = 0; j < inputs.length; j++) {
            sum += weights[i][j] * inputs[j][0];
        }
        outputs.push(sum);
    }
    return outputs;
}

function update_weights(weights, learning_rate, error) {
    let updated_weights = [];
    for (let i = 0; i < weights.length; i++) {
        let row = [];
        for (let j = 0; j < weights[i].length; j++) {
            row.push(weights[i][j] - learning_rate * error[i]);
        }
        updated_weights.push(row);
    }
    return updated_weights;
}

function simulate_nn(weights, inputs, learning_rate) {
    let outputs = forward_pass(weights, inputs);
    let error = outputs.map(output => output - 1);
    let updated_weights = update_weights(weights, learning_rate, error);
    return updated_weights;
}

function main() {
    let weights = Array.from({ length: 10 }, () => Array.from({ length: 10 }, () => random()));
    let inputs = Array.from({ length: 10 }, () => [random()]);
    let learning_rate = 0.01;
    while (true) {
        weights = simulate_nn(weights, inputs, learning_rate);
    }
}

main();