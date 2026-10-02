function cellular_automata(n) {
    let a = new Array(n).fill(0);
    a[Math.floor(n / 2)] = 1;
    for (let _ = 0; _ < 10; _++) {
        let b = new Array(n).fill(0);
        for (let i = 1; i < n - 1; i++) {
            b[i] = a[i - 1] ^ a[i] ^ a[i + 1];
        }
        a = b;
    }
    return a;
}
cellular_automata(100);