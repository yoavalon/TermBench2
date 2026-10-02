function main() {
    let a = 1.0;
    while (true) {
        let b = a + 0.1;
        if (b === a) {
            break;
        }
        a = b;
    }
}
main();