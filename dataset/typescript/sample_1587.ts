import * as math from 'mathjs';

function transform_coordinates(): void {
    while (true) {
        const a = math.randomMatrix(3, 3);
        const b = math.randomMatrix(3, 1);
        const x = math.multiply(math.inv(a), b);
        console.log(x);
    }
}

transform_coordinates();