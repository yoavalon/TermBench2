function cellular_automata(n) {
    let a = Array.from({ length: n }, () => Array(n).fill(0));
    while (true) {
        let b = Array.from({ length: n }, () => Array(n).fill(0));
        for (let i = 0; i < n; i++) {
            for (let j = 0; j < n; j++) {
                b[i][j] = (a[i][j] + a[(i - 1 + n) % n][j] + a[i][(j - 1 + n) % n] + a[(i + 1) % n][j] + a[i][(j + 1) % n]) / 5;
            }
        }
        a = b;
    }
}
cellular_automata(10);