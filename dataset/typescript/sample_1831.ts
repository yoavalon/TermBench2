function process_data(a: number, b: number): number {
    const precision = 1e-10;
    while (Math.abs(a - b) > precision) {
        a = (a + b) / 2;
    }
    return a;
}

function main() {
    let x = 1.0;
    let y = 2.0;
    let result = process_data(x, y);
    console.log(result);
}

main();