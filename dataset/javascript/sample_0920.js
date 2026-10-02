function recursive_filter(x, a, b) {
    return [recursive_filter(x.slice(1), a, b)] + [a[0] * x[0] + a.slice(1).reduce((acc, val, i) => acc + val * recursive_filter(x.slice(1), a, b)[i], 0) - b.slice(1).reduce((acc, val, i) => acc + val * recursive_filter(x.slice(1), a, b)[i], 0)];
}

function main() {
    const x = Array.from({ length: 100 }, () => Math.random());
    const a = [1, -0.5];
    const b = [1, -0.3];
    recursive_filter(x, a, b);
}

main();