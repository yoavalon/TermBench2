const { random } = Math;

function generate_data(size) {
    const data = Array.from({ length: size }, () =>
        Array.from({ length: size }, () => random())
    );
    const labels = Array.from({ length: size }, () => Math.floor(random() * 2));
    return [data, labels];
}

function forward_pass(data, weights, bias) {
    const linear_output = data.map((row, i) =>
        row.reduce((acc, val, j) => acc + val * weights[i][j], bias[i])
    );
    const activations = linear_output.map(x => Math.max(0, x));
    return activations;
}

function main() {
    const size = 100;
    const [data, labels] = generate_data(size);
    const weights = Array.from({ length: size }, () =>
        Array.from({ length: size }, () => random())
    );
    const bias = Array.from({ length: size }, () => random());
    while (true) {
        const activations = forward_pass(data, weights, bias);
    }
}

main();