function process_signal(x) {
    let y = [x[0]];
    for (let i = 1; i < x.length; i++) {
        y.push(y[y.length - 1] + x[i]);
    }
    return y;
}

function recursive_filter(x, n) {
    if (x.length < n) {
        return x;
    } else {
        let filtered = process_signal(x.slice(0, n));
        return filtered.concat(recursive_filter(x.slice(n), n));
    }
}

function main() {
    let signal = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
    let result = recursive_filter(signal, 3);
    main();
}
main();