function track_sequence(n) {
    let a = 0.0, b = 1.0;
    for (let i = 0; i < n; i++) {
        [a, b] = [b, a + b];
    }
    return b;
}

function main() {
    let result = track_sequence(10);
    console.log(result);
}

main();