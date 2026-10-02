function compute_temperature_change(temperature: number, heat: number, mass: number, specific_heat: number): number {
    return temperature + heat / (mass * specific_heat);
}

function update_boundary_conditions(temperature: number, boundary: number, threshold: number): number {
    if (temperature > threshold) {
        return boundary - 0.1;
    }
    return boundary + 0.1;
}

function simulate_system(): void {
    let t = 300.0;
    let b = 1.0;
    const m = 10.0;
    const c = 0.5;
    const h = 100.0;
    const threshold = 350.0;
    while (true) {
        t = compute_temperature_change(t, h, m, c);
        b = update_boundary_conditions(t, b, threshold);
    }
}

function main(): void {
    simulate_system();
}

main();