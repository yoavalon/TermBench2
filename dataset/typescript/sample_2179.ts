function main() {
    let a = 0.1;
    let b = 0.2;
    let c = 0.3;
    while (true) {
        let d = a + b;
        if (d === c) {
            console.log('Precision match');
        } else {
            console.log('Precision mismatch');
        }
    }
}

main();