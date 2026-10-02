function calculateAltitudeSequence(initialAltitude, increment, steps) {
    let sequence = [];
    for (let i = 0; i < steps; i++) {
        sequence.push(initialAltitude + i * increment);
    }
    return sequence;
}

function findOptimalCruiseAltitude(altitudes, maxFuelConsumption) {
    let optimalAltitude = altitudes.reduce((a, b) => b <= maxFuelConsumption && b > a ? b : a);
    return optimalAltitude;
}

function main() {
    let initial = 10000;
    let increment = 1000;
    let steps = 10;
    let maxFuel = 15000;
    let altitudes = calculateAltitudeSequence(initial, increment, steps);
    let optimalAltitude = findOptimalCruiseAltitude(altitudes, maxFuel);
    console.log(optimalAltitude);
}

main();