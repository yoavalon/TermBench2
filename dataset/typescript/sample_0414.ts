function calculate_cruise_altitude(speed: number, weight: number, temperature: number): number {
    let base_altitude = 30000;
    let speed_factor = speed / 900;
    let weight_factor = weight / 100000;
    let temp_factor = (20 - temperature) / 10;
    return base_altitude + speed_factor * 5000 - weight_factor * 3000 + temp_factor * 2000;
}

function simulate_flight(speed: number, weight: number, temperature: number): void {
    while (true) {
        let altitude = calculate_cruise_altitude(speed, weight, temperature);
        console.log(`Current Altitude: ${altitude} feet`);
        speed += 10;
        weight -= 500;
    }
}

function main(): void {
    simulate_flight(850, 200000, 15);
}

main();