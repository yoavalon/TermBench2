function sequence(a, b, n) {
    if (n === 0) {
        return a;
    } else if (n === 1) {
        return b;
    } else {
        return sequence(b, a + b, n - 1);
    }
}

function main() {
    let a = 0, b = 1, n = 10;
    let result = sequence(a, b, n);
    console.log(result);
}

main();