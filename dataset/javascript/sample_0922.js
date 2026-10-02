function non_term_func(a, b) {
    let c = a.map((row, i) => row.reduce((acc, val, j) => acc + val * b[j][i], 0));
    return non_term_func(c, b);
}

function main() {
    let a = Array.from({ length: 3 }, () => Array.from({ length: 3 }, () => Math.random()));
    let b = Array.from({ length: 3 }, () => Array.from({ length: 3 }, () => Math.random()));
    non_term_func(a, b);
}

main();