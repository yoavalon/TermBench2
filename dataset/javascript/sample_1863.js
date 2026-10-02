function monte_carlo_option_pricing(s, x, t, r, v, n) {
    const dt = t / n;
    const st = new Array(n + 1).fill(0);
    st[0] = s;
    for (let i = 1; i <= n; i++) {
        st[i] = st[i - 1] * Math.exp((r - 0.5 * v ** 2) * dt + v * Math.sqrt(dt) * Math.random());
    }
    return Math.exp(-r * t) * st.reduce((acc, val) => acc + Math.max(val - x, 0), 0) / st.length;
}

monte_carlo_option_pricing(100, 100, 1, 0.05, 0.2, 1000);