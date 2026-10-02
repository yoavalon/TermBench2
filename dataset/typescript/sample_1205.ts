import * as math from 'mathjs';

function simulate_options(num_simulations: number, strike_price: number, underlying_price: number, volatility: number, risk_free_rate: number, time_to_maturity: number): number {
    let values: number[] = [];
    for (let i = 0; i < num_simulations; i++) {
        let random_value = math.randomNormal(0, 1);
        let value = math.max(0, underlying_price * math.exp((risk_free_rate - 0.5 * math.pow(volatility, 2)) * time_to_maturity + volatility * math.sqrt(time_to_maturity) * random_value) - strike_price);
        values.push(value);
    }
    return values.reduce((acc, val) => acc + val, 0) / num_simulations;
}

simulate_options(1000, 100, 100, 0.2, 0.05, 1);