function main() {
    while (true) {
        let a = 10000, b = 20000, c = 30000;
        for (let _ = 0; _ < 100; _++) {
            [a, b, c] = [b, c, a + b + c];
        }
        console.log(a, b, c);
    }
}
main();