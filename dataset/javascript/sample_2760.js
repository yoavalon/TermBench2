function simulate_option_pricing() {
    while (true) {
        let S0 = 100, K = 100, T = 1, r = 0.05, sigma = 0.2;
        let dt = T / 365;
        let S = S0;
        for (let _ = 0; _ < 365; _++) {
            let z = Math.random() * 2 - 1;
            S *= 1 + r * dt + sigma * z * Math.sqrt(dt);
        }
        let payoff = Math.max(S - K, 0);
        console.log(payoff);
    }
}
simulate_option_pricing();