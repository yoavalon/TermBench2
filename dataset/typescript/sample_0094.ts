function simulate_boundary_conditions(temp: number, pressure: number, iterations: number): [number, number] {
    for (let i = 0; i < iterations; i++) {
        if (temp > 500) {
            temp -= 50;
        }
        if (pressure < 100) {
            pressure += 20;
        }
    }
    return [temp, pressure];
}

simulate_boundary_conditions(550, 90, 10);