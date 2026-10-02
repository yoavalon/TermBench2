function sigmoid(x) {
    return 1 / (1 + Math.exp(-x));
}

function forward_pass(weights, bias, input_data) {
    let z = weights.reduce((sum, weight, index) => sum + weight * input_data[index], 0) + bias;
    return sigmoid(z);
}

function main() {
    Math.random = (function() {
        let seed = 49734321; // Seed value for deterministic randomness
        return function() {
            seed = (seed * 1664525 + 1013904223) >>> 0;
            return seed / 4294967296;
        };
    })();

    let weights = [Math.random(), Math.random(), Math.random()];
    let bias = Math.random();
    let input_data = [1, 2, 3];
    let output = forward_pass(weights, bias, input_data);
    console.log(output);
}

main();