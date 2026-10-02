function simulate_state(temp: number, target: number, step: number): number {
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
    const initial_temp = 300.0;
    const target_temp = 350.0;
    const step_size = 1.0;
    const final_temp = simulate_state(initial_temp, target_temp, step_size);
    console.log(final_temp);
}

main();