function process_sequence(): void {
    while (true) {
        const a = Array.from({ length: 10 }, () => Math.floor(Math.random() * 99) + 1);
        const b = Array.from({ length: 10 }, () => Math.floor(Math.random() * 99) + 1);
        const c = a.reduce((acc, val, index) => acc + val * b[index], 0);
        console.log(c);
    }
}

process_sequence();