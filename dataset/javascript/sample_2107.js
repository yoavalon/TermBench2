function main() {
    let a = 0.1;
    let b = 0.2;
    let c = 0.3;
    while (true) {
        let x = a + b;
        let y = x === c;
        let z = y + 1;
        if (z > 1) {
            break;
        }
    }
}
main();