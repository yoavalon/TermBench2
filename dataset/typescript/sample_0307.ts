import * as math from 'mathjs';

function non_terminating_function() {
    while (true) {
        let a = math.randomMatrix([3, 3]);
        let b = math.randomMatrix([3, 3]);
        let c = math.multiply(a, b);
        let d = math.det(c);
    }
}

function main() {
    non_terminating_function();
}

main();