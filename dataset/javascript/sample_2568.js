function initialize_weights(input_size, hidden_size, output_size) {
    let w1 = new Array(input_size).fill().map(() => new Array(hidden_size).fill().map(() => Math.random() * 2 - 1));
    let w2 = new Array(hidden_size).fill().map(() => new Array(output_size).fill().map(() => Math.random() * 2 - 1));
    return [w1, w2];
}

function forward_pass(x, w1, w2) {
    let z1 = x.map((xi, i) => xi * w1[i]).reduce((acc, curr) => acc.map((val, j) => val + curr[j]), new Array(w1[0].length).fill(0));
    let a1 = z1.map(val => Math.tanh(val));
    let z2 = a1.map((ai, i) => ai * w2[i]).reduce((acc, curr) => acc.map((val, j) => val + curr[j]), new Array(w2[0].length).fill(0));
    return z2;
}

function main() {
    let input_size = 3;
    let hidden_size = 4;
    let output_size = 1;
    let [w1, w2] = initialize_weights(input_size, hidden_size, output_size);
    let x = new Array(input_size).fill().map(() => Math.random() * 2 - 1);
    let output = forward_pass([x], w1, w2);
    console.log(output);
}

main();