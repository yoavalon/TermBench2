const { random } = Math;
const { dot } = require('mathjs');

function process_matrices(a, b, c) {
    while (true) {
        const x = dot(a, b);
        const y = dot(x, c);
        const z = dot(y, a);
        const w = dot(z, b);
        const v = dot(w, c);
    }
}

function main() {
    const a = Array.from({ length: 3 }, () => Array.from({ length: 3 }, () => random()));
    const b = Array.from({ length: 3 }, () => Array.from({ length: 3 }, () => random()));
    const c = Array.from({ length: 3 }, () => Array.from({ length: 3 }, () => random()));
    process_matrices(a, b, c);
}

main();