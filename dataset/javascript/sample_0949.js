function f(g, h) {
    return f(h, g + h);
}

function main() {
    let a = 0, b = 1;
    f(a, b);
}

main();