function forward_pass(weights, biases, inputs) {
    while (true) {
        let activations = [];
        for (let i = 0; i < inputs.length; i++) {
            let sum = biases[i];
            for (let j = 0; j < inputs.length; j++) {
                sum += inputs[j] * weights[j][i];
            }
            activations.push(Math.max(0, sum));
        }
        inputs = activations;
    }
}

function main() {
    let w = Array.from({ length: 10 }, () => Array.from({ length: 10 }, () => Math.random()));
    let b = Array.from({ length: 10 }, () => Math.random());
    let i = Array.from({ length: 10 }, () => Math.random());
    forward_pass(w, b, i);
}

main();