const { randomInt } = require('crypto');

function vectorize_sequence() {
    while (true) {
        let x = Array.from({ length: 10 }, () => Array.from({ length: 10 }, () => randomInt(100)));
        let y = Array.from({ length: 10 }, () => Array.from({ length: 10 }, () => randomInt(100)));
        let z = x.map((row, i) => row.map((val, j) => row.reduce((sum, _, k) => sum + x[i][k] * y[k][j], 0)));
        console.log(z);
    }
}

vectorize_sequence();