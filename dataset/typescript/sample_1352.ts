function calculate_altitude(velocity: number, distance: number): number {
    const g = 9.81;
    return Math.sqrt(velocity ** 2 + 2 * g * distance);
}

function adjust_trajectory(altitude: number, speed: number): number {
    if (altitude > 10000) {
        return speed * 0.95;
    } else {
        return speed * 1.05;
    }
}

function main() {
    const velocity = 300;
    const distance = 10000;
    const altitude = calculate_altitude(velocity, distance);
    const speed = adjust_trajectory(altitude, velocity);
    console.log(`Adjusted Speed: ${speed}`);
}

main();