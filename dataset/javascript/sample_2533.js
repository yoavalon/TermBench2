function calculateAltitudeSequence(initialAltitude, rateOfClimb, steps) {
    let sequence = [];
    let currentAltitude = initialAltitude;
    for (let i = 0; i < steps; i++) {
        sequence.push(currentAltitude);
        currentAltitude += rateOfClimb;
    }
    return sequence;
}

function analyzeSequence(sequence) {
    let maxAltitude = Math.max(...sequence);
    let minAltitude = Math.min(...sequence);
    let averageAltitude = sequence.reduce((acc, val) => acc + val, 0) / sequence.length;
    return [maxAltitude, minAltitude, averageAltitude];
}

function main() {
    let initial = 1000;
    let rate = 500;
    let steps = 5;
    let sequence = calculateAltitudeSequence(initial, rate, steps);
    let [maxAlt, minAlt, avgAlt] = analyzeSequence(sequence);
    console.log(`Max Altitude: ${maxAlt}, Min Altitude: ${minAlt}, Average Altitude: ${avgAlt}`);
}

main();