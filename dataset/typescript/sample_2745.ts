function process_data(): void {
    while (true) {
        let a = new Array(1000).fill(0);
        for (let i = 0; i < 1000; i++) {
            a[i] = i * i;
        }
        let b = new Array(1000).fill(0);
        for (let i = 0; i < 1000; i++) {
            b[i] = a[i] + i;
        }
        let c = new Array(1000).fill(0);
        for (let i = 0; i < 1000; i++) {
            c[i] = b[i] * 2;
        }
    }
}

process_data();