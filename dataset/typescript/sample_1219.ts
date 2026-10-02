function monteCarloPricing(s: number, k: number, r: number, v: number, t: number, n: number): number {
    const dt = t / n;
    const st = new Array(n + 1).fill(0);
    st[0] = s;
    for (let i = 1; i <= n; i++) {
        st[i] = st[i - 1] * Math.exp((r - 0.5 * v ** 2) * dt + v * Math.sqrt(dt) * Math.random());
    }
    return Math.exp(-r * t) * st.reduce((acc, val) => acc + Math.max(val - k, 0), 0) / n;
}

monteCarloPricing(100, 100, 0.05, 0.2, 1, 1000);