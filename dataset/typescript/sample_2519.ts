function calculateAltitude(time: number): number {
    if (time < 10) {
        return 5000;
    } else if (time < 20) {
        return 10000;
    } else {
        return 15000;
    }
}

function simulateFlight(duration: number): number[] {
    const times = Array.from({ length: duration }, (_, i) => i + 1);
    const altitudes = times.map(calculateAltitude);
    return altitudes;
}

function main() {
    const flightDuration = 30;
    const trajectory = simulateFlight(flightDuration);
    trajectory.forEach((altitude, index) => {
        console.log(`Time: ${index + 1}, Altitude: ${altitude}`);
    });
}

main();