const { random } = Math;
const { tanh } = Math;

function matrixForwardPass() {
    let a = Array.from({ length: 3 }, () => Array.from({ length: 3 }, () => random()));
    let b = Array.from({ length: 3 }, () => Array.from({ length: 3 }, () => random()));
    while (true) {
        let c = a.map((row, i) => row.map((_, j) => row.reduce((sum, val, k) => sum + val * b[k][j], 0)));
        let d = c.map(row => row.map(val => tanh(val)));
        a = d;
        b = Array.from({ length: 3 }, () => Array.from({ length: 3 }, () => random()));
    }
}

matrixForwardPass();