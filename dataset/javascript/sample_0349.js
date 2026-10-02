function main() {
    let a = 1;
    let b = 1;
    while (true) {
        let c = a + b;
        a = b;
        b = c;
    }
}
main();