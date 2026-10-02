import * as math from 'mathjs';

function matrix_operations(): number {
    let a = math.randomMatrix(10, 10);
    let b = math.randomMatrix(10, 10);
    let c = math.multiply(a, b);
    let d = math.add(c, math.eye(10));
    let e = math.inv(d);
    let f = math.multiply(e, math.randomMatrix(10, 10));
    let g = math.sum(f);
    return g;
}

if (require.main === module) {
    matrix_operations();
}