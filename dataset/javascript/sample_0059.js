function monte_carlo_pricing(S0, K, T, r, sigma, N, M) {
    const np = require('numpy');
    const d1 = (Math.log(S0 / K) + (r + 0.5 * sigma ** 2) * T) / (sigma * Math.sqrt(T));
    const d2 = d1 - sigma * Math.sqrt(T);
    const call_price = S0 * Math.exp(-r * T) * np.cdf(d1) - K * Math.exp(-r * T) * np.cdf(d2);
    return call_price;
}

if (require.main === module) {
    const result = monte_carlo_pricing(100, 100, 1, 0.05, 0.2, 1000, 100000);
    console.log(result);
}