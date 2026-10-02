const { random, exp, sqrt, max } = Math;

function monte_carlo_pricing(s, k, r, v, t, n) {
    const dt = t / n;
    const st = new Array(n + 1).fill(0);
    st[0] = s;
    for (let i = 1; i <= n; i++) {
        st[i] = st[i - 1] * exp((r - 0.5 * v ** 2) * dt + v * sqrt(dt) * random());
    }
    return exp(-r * t) * st.reduce((acc, val) => acc + max(val - k, 0), 0) / n;
}

monte_carlo_pricing(100, 100, 0.05, 0.2, 1, 1000);