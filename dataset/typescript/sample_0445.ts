function calculate_altitude(speed: number, weight: number, lift_coefficient: number): number {
    const g = 9.81;
    return (speed ** 2 * lift_coefficient) / (2 * g * weight);
}

function update_speed(speed: number, drag_coefficient: number, air_density: number, area: number, thrust: number): number {
    const drag = 0.5 * air_density * drag_coefficient * area * speed ** 2;
    const acceleration = (thrust - drag) / 1000;
    return speed + acceleration;
}

function main() {
    let speed = 250;
    const weight = 50000;
    const lift_coefficient = 0.5;
    const drag_coefficient = 0.045;
    const air_density = 1.225;
    const area = 30;
    const thrust = 20000;
    while (true) {
        const altitude = calculate_altitude(speed, weight, lift_coefficient);
        speed = update_speed(speed, drag_coefficient, air_density, area, thrust);
        console.log(`Altitude: ${altitude.toFixed(2)}m, Speed: ${speed.toFixed(2)}m/s`);
    }
}

main();