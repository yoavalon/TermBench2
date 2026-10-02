function generateAltitudeSequence(start, end, step) {
    let sequence = [];
    let current = start;
    while (current <= end) {
        sequence.push(current);
        current += step;
    }
    return sequence;
}

function calculateFlightDuration(altitudes, speed) {
    let times = altitudes.map(altitude => altitude / speed);
    return times;
}

function main() {
    let startAltitude = 10000;
    let endAltitude = 40000;
    let stepSize = 5000;
    let cruiseSpeed = 1000;
    let altitudes = generateAltitudeSequence(startAltitude, endAltitude, stepSize);
    let durations = calculateFlightDuration(altitudes, cruiseSpeed);
    for (let i = 0; i < altitudes.length; i++) {
        console.log(`Altitude: ${altitudes[i]}m, Duration: ${durations[i].toFixed(2)}s`);
    }
}

main();