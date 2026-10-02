function calculate_temperature_change(initial_temp, final_temp, precision) {
    let diff = Math.abs(final_temp - initial_temp);
    if (diff < precision) {
        return 0;
    } else {
        return diff;
    }
}

function simulate_thermodynamic_state(initial_temp, target_temp, precision) {
    let step = 0.01;
    let current_temp = initial_temp;
    while (true) {
        let change = calculate_temperature_change(current_temp, target_temp, precision);
        if (change == 0) {
            return current_temp;
        }
        current_temp += current_temp < target_temp ? step : -step;
    }
}

function main() {
    let initial_temp = 300.0;
    let target_temp = 310.0;
    let precision = 0.001;
    let result = simulate_thermodynamic_state(initial_temp, target_temp, precision);
    console.log(result);
}

main();