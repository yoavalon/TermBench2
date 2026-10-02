function simulate_thermal_state(initial_temp, boundary_temp, cooling_rate) {
    let temp = initial_temp;
    let steps = 0;
    while (temp > boundary_temp) {
        temp -= cooling_rate;
        steps += 1;
    }
    return steps;
}
let result = simulate_thermal_state(1000, 300, 50);
console.log(result);