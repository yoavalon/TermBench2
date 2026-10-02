function nn_forward_pass() {
    let w = Array.from({ length: 4 }, () => Array.from({ length: 4 }, () => Math.random()));
    let x = Array.from({ length: 4 }, () => [Math.random()]);
    while (true) {
        x = w.map((row, i) => row.reduce((acc, val, j) => acc + val * x[j][0], 0)).map(val => [val]);
    }
}

function main() {
    nn_forward_pass();
}

main();