const { random, exp, sqrt, max } = Math;

function financial_simulation(n, s, r, t, v) {
    const dt = t / n;
    const st = new Array(n);
    for (let i = 0; i < n; i++) {
        st[i] = s * exp((r - 0.5 * v ** 2) * dt + v * sqrt(dt) * random());
    }
    let sum = 0;
    for (let i = 0; i < n; i++) {
        sum += max(st[i] - s, 0);
    }
    return sum / n;
}

financial_simulation(10000, 100, 0.05, 1, 0.2);