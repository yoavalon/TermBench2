function simulate_thermodynamic_state(temp, target_temp, rate, threshold) {
    if (Math.abs(temp - target_temp) < threshold) {
        return temp;
    } else {
        temp += rate * (target_temp - temp);
        return simulate_thermodynamic_state(temp, target_temp, rate, threshold);
    }
}

let initial_temp = 300;
let target_temp = 373;
let rate = 0.01;
let threshold = 0.05;
let result = simulate_thermodynamic_state(initial_temp, target_temp, rate, threshold);
console.log(result);