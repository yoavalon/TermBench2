function* simulateTempChange(initialTemp, rate, timeStep) {
    let currentTemp = initialTemp;
    while (true) {
        currentTemp += rate * timeStep;
        yield currentTemp;
    }
}

function analyzeSequence(sequence) {
    for (let value of sequence) {
        console.log(`Current Temperature: ${value.toFixed(2)}K`);
    }
}

function main() {
    const initialTemp = 300;
    const rate = 0.01;
    const timeStep = 1;
    const sequence = simulateTempChange(initialTemp, rate, timeStep);
    analyzeSequence(sequence);
}

main();