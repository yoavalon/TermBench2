function simulateTemperatureChange(initialTemp, rate, steps) {
    let temperature = initialTemp;
    for (let i = 0; i < steps; i++) {
        temperature += rate * Math.random();
    }
    return temperature;
}

function analyzeSimulationResults(initialTemp, finalTemp) {
    return finalTemp - initialTemp;
}

function main() {
    let initialTemperature = 300.0;
    let rateOfChange = 0.5;
    let numberOfSteps = 1000;
    let finalTemperature = simulateTemperatureChange(initialTemperature, rateOfChange, numberOfSteps);
    let temperatureDifference = analyzeSimulationResults(initialTemperature, finalTemperature);
    console.log(`Initial Temperature: ${initialTemperature}, Final Temperature: ${finalTemperature}, Change: ${temperatureDifference}`);
}

main();