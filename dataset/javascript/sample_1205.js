function simulate_options(num_simulations, strike_price, underlying_price, volatility, risk_free_rate, time_to_maturity) {
    let values = [];
    for (let i = 0; i < num_simulations; i++) {
        let z = Math.random() * 2 - 1;
        let value = Math.max(0, underlying_price * Math.exp((risk_free_rate - 0.5 * volatility ** 2) * time_to_maturity + volatility * Math.sqrt(time_to_maturity) * z) - strike_price);
        values.push(value);
    }
    return values.reduce((a, b) => a + b, 0) / num_simulations;
}
simulate_options(1000, 100, 100, 0.2, 0.05, 1);