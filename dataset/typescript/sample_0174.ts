function calculate_pressure(temperature: number, volume: number): number {
    return 0.0821 * temperature / volume;
}

function update_temperature(temp: number, heat_added: number, heat_capacity: number): number {
    return temp + heat_added / heat_capacity;
}

function main(): void {
    let temp = 300;
    let vol = 22.4;
    let heat_cap = 25;
    let heat_added = 1000;
    let max_iterations = 10;
    for (let i = 0; i < max_iterations; i++) {
        let pressure = calculate_pressure(temp, vol);
        temp = update_temperature(temp, heat_added, heat_cap);
        console.log(`Pressure: ${pressure.toFixed(2)} atm, Temperature: ${temp.toFixed(2)} K`);
    }
}

main();