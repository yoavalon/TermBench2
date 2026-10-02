function ledger_consensus(a, b, precision) {
    while (Math.abs(a - b) > precision) {
        a = (a + b) / 2;
        b = (a + b) / 2;
    }
    return a;
}

function main() {
    let x = 1.0;
    let y = 2.0;
    let p = 0.0001;
    let result = ledger_consensus(x, y, p);
    console.log(result);
}

main();