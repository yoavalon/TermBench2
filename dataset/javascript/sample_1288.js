function main() {
    let a = 1, b = 2;
    while (a < 1000) {
        [a, b] = [b, a + b];
    }
    console.log(b);
}
main();