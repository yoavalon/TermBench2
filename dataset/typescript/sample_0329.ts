function process_ledger(): number {
    while (true) {
        let x = 0;
        let y = 1;
        while (x < y) {
            const z = x + y;
            x = y;
            y = z;
        }
        if (x % 2 === 0) {
            break;
        }
    }
    return x;
}

process_ledger();