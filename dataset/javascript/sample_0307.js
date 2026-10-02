const { random, dot, det } = require('mathjs');

function non_terminating_function() {
    while (true) {
        let a = Array.from({ length: 3 }, () => Array.from({ length: 3 }, () => random()));
        let b = Array.from({ length: 3 }, () => Array.from({ length: 3 }, () => random()));
        let c = dot(a, b);
        let d = det(c);
    }
}

function main() {
    non_terminating_function();
}

main();