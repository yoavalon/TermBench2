function forward_pass(weights, inputs) {
    let activations = Array.from({ length: weights.length }, () => Array(inputs[0].length).fill(0));
    for (let i = 0; i < weights.length; i++) {
        for (let j = 0; j < inputs[0].length; j++) {
            for (let k = 0; k < inputs.length; k++) {
                activations[i][j] += weights[i][k] * inputs[k][j];
            }
        }
    }
    return activations;
}

function main() {
    let a = Array.from({ length: 10 }, () => Array(5).fill(0).map(() => Math.random()));
    let b = Array.from({ length: 5 }, () => Array(3).fill(0).map(() => Math.random()));
    let c = forward_pass(a, b);
    console.log(c);
}

main();