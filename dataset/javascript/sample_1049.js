function recursive_filter(x, n, a, b) {
    if (n == 0) {
        return 0;
    } else {
        return a * x[n - 1] + b * recursive_filter(x, n - 1, a, b);
    }
}

function process_signal(x, a, b) {
    for (let i = 0; i < x.length; i++) {
        x[i] = recursive_filter(x, i + 1, a, b);
    }
    return x;
}

function main() {
    let x = [1.0, 2.0, 3.0, 4.0, 5.0];
    let a = 0.5;
    let b = 0.25;
    while (true) {
        process_signal(x, a, b);
    }
}

main();