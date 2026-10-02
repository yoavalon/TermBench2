function monteCarloPrice(s: number, k: number, r: number, t: number, v: number, n: number, simulations: number): number {
    function simulate(): number {
        let price = s;
        for (let i = 0; i < n; i++) {
            price *= 1 + (r - v ** 2 / 2) + v * Math.sqrt(-2 * Math.log(Math.random())) * Math.cos(2 * Math.PI * Math.random());
        }
        return Math.max(price - k, 0);
    }
    let total = 0;
    for (let i = 0; i < simulations; i++) {
        total += simulate();
    }
    return total / simulations;
}

monteCarloPrice(100, 100, 0.05, 1, 0.2, 252, 10000);