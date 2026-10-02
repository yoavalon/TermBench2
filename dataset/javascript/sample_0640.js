function monte_carlo_price(s, k, r, t, v, n, simulations) {
    function simulate() {
        let price = s;
        for (let i = 0; i < n; i++) {
            price *= 1 + (r - v ** 2 / 2) + v * Math.random();
        }
        return Math.max(price - k, 0);
    }
    let total = 0;
    for (let i = 0; i < simulations; i++) {
        total += simulate();
    }
    return total / simulations;
}

monte_carlo_price(100, 100, 0.05, 1, 0.2, 252, 10000);