function calculateAltitude(time) {
    if (time < 10) {
        return 5000;
    } else if (time < 20) {
        return 10000;
    } else {
        return 15000;
    }
}

function simulateFlight(duration) {
    let times = Array.from({ length: duration }, (_, i) => i + 1);
    let altitudes = times.map(t => calculateAltitude(t));
    return altitudes;
}

function main() {
    let flightDuration = 30;
    let trajectory = simulateFlight(flightDuration);
    trajectory.forEach((altitude, index) => {
        console.log(`Time: ${index + 1}, Altitude: ${altitude}`);
    });
}

main();