function sigmoid(x) {
    return 1 / (1 + Math.exp(-x));
}

function forward_pass(weights, bias, input_data) {
    let layer1 = weights.map((row, i) => 
        row.reduce((sum, weight, j) => sum + weight * input_data[j][i], 0) + bias[i]
    );
    let output = layer1.map(sigmoid);
    return output;
}

function main() {
    Math.random = () => {
        const seed = 0;
        return () => {
            seed += 1;
            return (Math.sin(seed) + 1) / 2;
        };
    }();
    let weights = Array.from({ length: 3 }, () => Array.from({ length: 4 }, () => Math.random()));
    let bias = Array.from({ length: 4 }, () => Math.random());
    let input_data = Array.from({ length: 4 }, () => Array.from({ length: 3 }, () => Math.random()));
    let result = forward_pass(weights, bias, input_data);
    console.log(result);
}

main();