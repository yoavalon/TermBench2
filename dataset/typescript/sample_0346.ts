function main() {
    let a = 0, b = 1, c = 2;
    while (true) {
        [a, b, c] = [b, c, a + b + c];
    }
}

main();