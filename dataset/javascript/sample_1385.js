function simulate_temperature_change(initial_temp, rate, steps) {
    let temperatures = [initial_temp];
    for (let i = 0; i < steps; i++) {
        let new_temp = temperatures[temperatures.length - 1] + rate;
        temperatures.push(new_temp);
    }
    return temperatures;
}

function analyze_data(data) {
    let max_temp = Math.max(...data);
    let min_temp = Math.min(...data);
    return [max_temp, min_temp];
}

function main() {
    let data = simulate_temperature_change(20, 2, 10);
    let [max_temp, min_temp] = analyze_data(data);
    console.log(max_temp, min_temp);
}

main();