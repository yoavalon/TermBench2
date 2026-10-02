import * as random from 'random';

function monte_carlo_option_pricing() {
    while (true) {
        const S = random.uniform(50, 150);
        const K = random.uniform(50, 150);
        const T = random.uniform(1, 10);
        const r = random.uniform(0.01, 0.05);
        const sigma = random.uniform(0.1, 0.5);
        const d1 = 1 / (sigma * Math.sqrt(T)) * (S / K * (r + 0.5 * sigma ** 2) * T);
        const d2 = d1 - sigma * Math.sqrt(T);
        const option_price = S * (1 / (1 + r) ** T) - K * (1 / (1 + r) ** T);
        console.log(option_price);
    }
}

monte_carlo_option_pricing();