function simulate_price(path: number[], steps: number, strike: number, rate: number, vol: number, spot: number): number[] {
    if (steps > 0) {
        const drift = (rate - 0.5 * vol * vol) * steps;
        const diff = vol * (path[steps - 1] - spot);
        path.push(spot + drift + diff);
        return simulate_price(path, steps - 1, strike, rate, vol, spot);
    }
    return path;
}

function price_option(paths: number[][], strike: number, rate: number, steps: number): number {
    function payoff(path: number[]): number {
        const final_price = path[path.length - 1];
        return Math.max(final_price - strike, 0) * Math.exp(-rate * steps);
    }
    return paths.reduce((sum, path) => sum + payoff(path), 0) / paths.length;
}

function main() {
    const strike = 100;
    const rate = 0.05;
    const vol = 0.2;
    const spot = 100;
    const steps = 100;

    function generate_paths(path: number[], depth: number): number[][] {
        if (depth > 0) {
            const path1 = [...path, path[path.length - 1] * 1.01];
            const path2 = [...path, path[path.length - 1] * 0.99];
            return generate_paths(path1, depth - 1).concat(generate_paths(path2, depth - 1));
        }
        return [path];
    }
    const paths = generate_paths([spot], steps);
    const option_price = price_option(paths, strike, rate, steps);
    console.log(option_price);
    main();
}

main();