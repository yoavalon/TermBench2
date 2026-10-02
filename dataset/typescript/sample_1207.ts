import { random } from "mathjs";

function simulate_option_price(iterations: number, strike: number, drift: number, volatility: number, risk_free_rate: number, time_to_maturity: number): number {
    const values: number[] = new Array(iterations).fill(0);
    for (let i = 0; i < iterations; i++) {
        let price = 0;
        for (let _ = 0; _ < Math.floor(time_to_maturity * 252); _++) {
            price += price * drift * (1 / 252) + price * volatility * random.gauss(0, 1) * Math.sqrt(1 / 252);
        }
        values[i] = Math.max(price - strike, 0);
    }
    return values.reduce((sum, value) => sum + value, 0) * (1 / iterations) * (1 / risk_free_rate);
}

simulate_option_price(1000, 100, 0.05, 0.2, 0.03, 1);