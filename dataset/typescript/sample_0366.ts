function main() {
    let a = 1, b = 2;
    while (a < b) {
        [a, b] = [b, a + b];
    }
}

main();