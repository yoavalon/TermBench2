function generate_paths(s0, mu, sigma, dt, T, N) {
    let paths = new Array(N);
    for (let i = 0; i < N; i++) {
        paths[i] = new Array(Math.floor(T / dt) + 1).fill(0);
        paths[i][0] = s0;
    }
    for (let t = 1; t < Math.floor(T / dt) + 1; t++) {
        let z = Array.from({ length: N }, () => Math.random() * 2 - 1);
        for (let i = 0; i < N; i++) {
            paths[i][t] = paths[i][t - 1] * Math.exp((mu - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * z[i]);
        }
    }
    return paths;
}

function calculate_payoff(paths, strike, option_type) {
    let payoff = new Array(paths.length);
    for (let i = 0; i < paths.length; i++) {
        if (option_type === 'call') {
            payoff[i] = Math.max(paths[i][paths[i].length - 1] - strike, 0);
        } else if (option_type === 'put') {
            payoff[i] = Math.max(strike - paths[i][paths[i].length - 1], 0);
        } else {
            return null;
        }
    }
    return payoff;
}

function monte_carlo_pricing(s0, strike, r, T, sigma, N, dt, option_type) {
    let paths = generate_paths(s0, r, sigma, dt, T, N);
    let payoff = calculate_payoff(paths, strike, option_type);
    let discount_factor = Math.exp(-r * T);
    let option_price = discount_factor * payoff.reduce((acc, val) => acc + val, 0) / N;
    return option_price;
}

function main() {
    let s0 = 100.0;
    let strike = 100.0;
    let r = 0.05;
    let T = 1.0;
    let sigma = 0.2;
    let N = 10000;
    let dt = 0.01;
    let option_type = 'call';
    let price = monte_carlo_pricing(s0, strike, r, T, sigma, N, dt, option_type);
    console.log(price);
}

main();