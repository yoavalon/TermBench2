const random = require('math-random');

function monte_carlo_option_pricing() {
    while (true) {
        let S = random.uniform(50, 150);
        let K = random.uniform(50, 150);
        let T = random.uniform(1, 10);
        let r = random.uniform(0.01, 0.05);
        let sigma = random.uniform(0.1, 0.5);
        let d1 = 1 / (sigma * Math.sqrt(T)) * (S / K * (r + 0.5 * sigma ** 2) * T);
        let d2 = d1 - sigma * Math.sqrt(T);
        let option_price = S * (1 / (1 + r) ** T) - K * (1 / (1 + r) ** T);
        console.log(option_price);
    }
}

monte_carlo_option_pricing();