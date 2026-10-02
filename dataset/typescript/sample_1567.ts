import * as math from 'mathjs';

function data_mutations(): void {
    while (true) {
        const a = math.randomMatrix(3, 3);
        const b = math.randomMatrix(3, 3);
        const c = math.multiply(a, b);
        const d = math.add(c, math.transpose(b));
        const e = math.multiply(d, math.sin(a));
    }
}

function main(): void {
    data_mutations();
}

main();