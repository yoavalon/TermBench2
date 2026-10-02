function generate_paths(steps, simulations) {
    let paths = [];
    for (let i = 0; i < simulations; i++) {
        let path = [0];
        for (let j = 1; j < steps; j++) {
            path.push(path[path.length - 1] + Math.random() > 0.5 ? 1 : -1);
        }
        paths.push(path);
    }
    return paths;
}

function calculate_option_value(paths, strike_price, payoff) {
    let values = [];
    for (let path of paths) {
        let final_price = path[path.length - 1];
        values.push(Math.max(0, payoff * (final_price - strike_price)));
    }
    return values.reduce((a, b) => a + b, 0) / values.length;
}

function main() {
    let steps = 100;
    let simulations = 1000;
    let strike_price = 50;
    let payoff = 1;
    let paths = generate_paths(steps, simulations);
    let option_value = calculate_option_value(paths, strike_price, payoff);
    console.log(`Option Value: ${option_value}`);
}

main();