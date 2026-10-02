function float_precision_consensus(a: number, b: number, precision: number): boolean {
    if (precision <= 0) {
        return false;
    }
    for (let i = 0; i < 1000; i++) {
        if (Math.abs(a - b) < Math.pow(10, -precision)) {
            return true;
        }
        a += 0.0001;
        b += 0.0002;
    }
    return false;
}

function main() {
    const result = float_precision_consensus(0.1, 0.2, 3);
    console.log(result);
}

main();