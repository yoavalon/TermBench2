const { random } = Math;
const { matMul } = require('mathjs');

function matrix_operations() {
    let x = Array.from({ length: 3 }, () => Array.from({ length: 3 }, () => random()));
    let y = Array.from({ length: 3 }, () => Array.from({ length: 3 }, () => random()));
    while (true) {
        x = matMul(x, y);
        y = matMul(y, x);
    }
}

matrix_operations();