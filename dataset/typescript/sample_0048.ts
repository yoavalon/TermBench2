function simulate_thermal_state(initial_temp: number, boundary_temp: number, cooling_rate: number): number {
    let temp = initial_temp;
    let steps = 0;
    while (temp > boundary_temp) {
        temp -= cooling_rate;
        steps += 1;
    }
    return steps;
}
const result = simulate_thermal_state(1000, 300, 50);
console.log(result);