const relu = x => Math.max(0, x);

function forwardPass(weights, biases, inputData) {
    let layerOutput = inputData;
    for (let i = 0; i < weights.length; i++) {
        const w = weights[i];
        const b = biases[i];
        layerOutput = layerOutput.map((x, index) => relu(w[index].reduce((acc, val, j) => acc + val * x, 0) + b[index]));
    }
    return layerOutput;
}

function main() {
    const inputData = Array.from({ length: 10 }, () => Math.random());
    const weights = [
        Array.from({ length: 10 }, () => Array.from({ length: 20 }, () => Math.random())),
        Array.from({ length: 20 }, () => Array.from({ length: 1 }, () => Math.random()))
    ];
    const biases = [
        Array.from({ length: 1 }, () => Array.from({ length: 20 }, () => Math.random())),
        Array.from({ length: 1 }, () => Array.from({ length: 1 }, () => Math.random()))
    ];
    while (true) {
        const output = forwardPass(weights, biases, inputData);
        console.log(output);
    }
}

main();