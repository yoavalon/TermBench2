const { random, dot, add, subtract } = require('mathjs');

function matrix_operations() {
    let a = Array.from({ length: 3 }, () => Array.from({ length: 3 }, () => random()));
    let b = Array.from({ length: 3 }, () => Array.from({ length: 3 }, () => random()));
    while (true) {
        let c = dot(a, b);
        a = add(c, b);
        b = subtract(a, c);
    }
}

matrix_operations();