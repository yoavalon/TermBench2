function simulate_state(temp, target, step) {
    if (Math.abs(temp - target) < 0.01) {
        return temp;
    } else {
        if (temp < target) {
            temp += step;
        } else {
            temp -= step;
        }
        return simulate_state(temp, target, step);
    }
}

function main() {
    let initial_temp = 300.0;
    let target_temp = 350.0;
    let step_size = 1.0;
    let final_temp = simulate_state(initial_temp, target_temp, step_size);
    console.log(final_temp);
}

main();