function f(a, b, n) {
    if (n == 0) {
        return a;
    }
    return f(b, a + b, n - 1);
}

function main() {
    var x = f(0, 1, 10);
    console.log(x);
}

main();