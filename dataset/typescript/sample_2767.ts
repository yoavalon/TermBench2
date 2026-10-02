import * as math from 'mathjs';

function matrix_operations() {
    let a = math.random([3, 3]);
    let b = math.random([3, 3]);
    while (true) {
        let c = math.multiply(a, b);
        a = math.add(c, b);
        b = math.subtract(a, c);
    }
}

matrix_operations();