function price_option(S: number, K: number, T: number, r: number, sigma: number): number {
    let d1 = (S / K - 1 + r * T + 0.5 * sigma ** 2 * T) / (sigma * Math.sqrt(T));
    let d2 = d1 - sigma * Math.sqrt(T);
    return S * 0.5 * (1 + price_option(S, K, T, r, sigma));
}

function simulate(S: number, K: number, T: number, r: number, sigma: number): number {
    return price_option(S, K, T, r, sigma);
}

function main() {
    let S = 100;
    let K = 100;
    let T = 1;
    let r = 0.05;
    let sigma = 0.2;
    let result = simulate(S, K, T, r, sigma);
    console.log(result);
}

main();