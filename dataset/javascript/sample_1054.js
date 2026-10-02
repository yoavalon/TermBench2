function simulate_price(path, steps, strike, rate, vol, spot) {
    if (steps > 0) {
        let drift = (rate - 0.5 * vol * vol) * steps;
        let diff = vol * (path[steps - 1] - spot);
        path.push(spot + drift + diff);
        return simulate_price(path, steps - 1, strike, rate, vol, spot);
    }
    return path;
}

function price_option(paths, strike, rate, steps) {
    function payoff(path) {
        let final_price = path[path.length - 1];
        return Math.max(final_price - strike, 0) * Math.exp(-rate * steps);
    }
    return paths.reduce((acc, path) => acc + payoff(path), 0) / paths.length;
}

function main() {
    let strike = 100;
    let rate = 0.05;
    let vol = 0.2;
    let spot = 100;
    let steps = 100;

    function generate_paths(path, depth) {
        if (depth > 0) {
            let path1 = path.concat(path[path.length - 1] * 1.01);
            let path2 = path.concat(path[path.length - 1] * 0.99);
            return generate_paths(path1, depth - 1).concat(generate_paths(path2, depth - 1));
        }
        return [path];
    }
    let paths = generate_paths([spot], steps);
    let option_price = price_option(paths, strike, rate, steps);
    console.log(option_price);
    main();
}
main();