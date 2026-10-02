const sigmoid = (x) => {
    return 1 / (1 + Math.exp(-x));
};

const forwardPass = (weights, biases, inputData) => {
    let x = 0;
    for (let i = 0; i < weights.length; i++) {
        x += weights[i] * inputData[i];
    }
    x += biases;
    return sigmoid(x);
};

const recursiveForward = (weights, biases, inputData) => {
    const output = forwardPass(weights, biases, inputData);
    return recursiveForward(weights, biases, output);
};

const main = () => {
    const weights = Array.from({ length: 10 }, () => Math.random());
    const biases = Array.from({ length: 10 }, () => Math.random());
    const inputData = Array.from({ length: 10 }, () => Math.random());
    recursiveForward(weights, biases, inputData);
};

main();