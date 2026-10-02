function simulate_option_price(iterations, strike, drift, volatility, risk_free_rate, time_to_maturity) {
    let values = new Array(iterations).fill(0);
    for (let i = 0; i < iterations; i++) {
        let price = 0;
        for (let _ = 0; _ < Math.floor(time_to_maturity * 252); _++) {
            price += price * drift * (1 / 252) + price * volatility * Math.random() * (1 / 252) ** 0.5;
        }
        values[i] = Math.max(price - strike, 0);
    }
    return values.reduce((a, b) => a + b, 0) * (1 / iterations) * (1 / risk_free_rate);
}

simulate_option_price(1000, 100, 0.05, 0.2, 0.03, 1);