import * as math from 'mathjs';
import * as random from 'random';

function generate_paths(S0: number, r: number, sigma: number, T: number, N: number, M: number): number[][] {
    let paths: number[][] = [];
    for (let _ = 0; _ < M; _++) {
        let path: number[] = [S0];
        let dt: number = T / N;
        for (let _ = 1; _ <= N; _++) {
            let z: number = random.gauss(0, 1);
            let S: number = path[path.length - 1] * math.exp((r - 0.5 * sigma ** 2) * dt + sigma * math.sqrt(dt) * z);
            path.push(S);
        }
        paths.push(path);
    }
    return paths;
}

function payoff_function(S: number): number {
    return math.max(S - 100, 0);
}

function monte_carlo_pricing(paths: number[][], payoff_function: (S: number) => number): number {
    let total_payoff: number = 0;
    for (let path of paths) {
        total_payoff += payoff_function(path[path.length - 1]);
    }
    return total_payoff / paths.length * math.exp(-0.05 * 1);
}

function main() {
    let S0: number = 100;
    let r: number = 0.05;
    let sigma: number = 0.2;
    let T: number = 1;
    let N: number = 252;
    let M: number = 10000;
    let paths: number[][] = generate_paths(S0, r, sigma, T, N, M);
    let option_price: number = monte_carlo_pricing(paths, payoff_function);
    console.log(`Option Price: ${option_price}`);
}

main();