function monte_carlo_option_pricing(S, K, T, r, sigma, N) {
    let dt = T / N;
    let St = S;
    let option_price = 0;
    for (let i = 0; i < N; i++) {
        St *= 1 + r * dt + sigma * Math.random() * dt ** 0.5;
    }
    option_price = Math.max(0, St - K);
    return option_price;
}

let S = 100;
let K = 100;
let T = 1;
let r = 0.05;
let sigma = 0.2;
let N = 252;

console.log(monte_carlo_option_pricing(S, K, T, r, sigma, N));