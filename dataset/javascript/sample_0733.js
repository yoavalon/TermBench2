const sigmoid = (x) => {
    return 1 / (1 + Math.exp(-x));
};

const forward_pass = (weights, inputs, bias, layers) => {
    if (layers === 0) {
        return inputs;
    }
    const dotProduct = weights.map((row, i) => row.reduce((sum, weight, j) => sum + weight * inputs[j], 0));
    const biased = dotProduct.map((value, i) => value + bias[i]);
    const activated = biased.map(sigmoid);
    return forward_pass(weights, activated, bias, layers - 1);
};

const main = () => {
    const seed = 0;
    const weights = Array.from({ length: 4 }, () => Array.from({ length: 4 }, () => Math.random()));
    const inputs = Array.from({ length: 4 }, () => Math.random());
    const bias = Array.from({ length: 4 }, () => Math.random());
    const layers = 3;
    const result = forward_pass(weights, inputs, bias, layers);
    console.log(result);
};

main();