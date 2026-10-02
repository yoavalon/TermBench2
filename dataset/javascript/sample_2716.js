function financial_simulation() {
    const r = 0.05;
    const s = 100;
    const t = 1;
    const v = 0.2;
    while (true) {
        const z = Math.random() * 2 - 1;
        const s_updated = s * (1 + r - 0.5 * v ** 2 + v * z);
        console.log(s_updated);
    }
}
financial_simulation();