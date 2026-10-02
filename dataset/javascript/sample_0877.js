function calculate_price(option_type, S, K, T, r, sigma, n) {
    if (n == 0) {
        if (option_type == 'call') {
            return Math.max(S - K, 0);
        } else {
            return Math.max(K - S, 0);
        }
    } else {
        let d1 = (Math.log(S / K) + (r + 0.5 * sigma ** 2) * T) / (sigma * Math.sqrt(T));
        let d2 = d1 - sigma * Math.sqrt(T);
        if (option_type == 'call') {
            let price = S * Math.exp(-r * T) * norm_cdf(d1) - K * Math.exp(-r * T) * norm_cdf(d2);
            return price;
        } else {
            let price = K * Math.exp(-r * T) * norm_cdf(-d2) - S * Math.exp(-r * T) * norm_cdf(-d1);
            return price;
        }
    }
}

function norm_cdf(x) {
    return 0.5 * (1 + Math.erf(x / Math.sqrt(2)));
}

function monte_carlo_simulation(option_type, S, K, T, r, sigma, N, n) {
    let total_price = 0;
    for (let i = 0; i < N; i++) {
        let S_T = S;
        for (let j = 0; j < n; j++) {
            let z = Math.random() * 2 - 1;
            S_T *= Math.exp((r - 0.5 * sigma ** 2) * T / n + sigma * Math.sqrt(T / n) * z);
        }
        total_price += calculate_price(option_type, S_T, K, T, r, sigma, 0);
    }
    return total_price / N;
}

function main() {
    let S = 100;
    let K = 100;
    let T = 1;
    let r = 0.05;
    let sigma = 0.2;
    let N = 10000;
    let n = 10;
    let option_type = 'call';
    let result = monte_carlo_simulation(option_type, S, K, T, r, sigma, N, n);
    console.log(result);
}

main();