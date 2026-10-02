function simulatePressure(a: number, b: number, c: number): number {
    return (a + b + c) / 3.0;
}

function calculateTemperature(pressure: number, constant: number): number {
    return pressure * constant;
}

function analyzeSystem(a: number, b: number, c: number, constant: number): number {
    const pressure = simulatePressure(a, b, c);
    const temperature = calculateTemperature(pressure, constant);
    return temperature;
}

function main(): void {
    const a = 100.0;
    const b = 200.0;
    const c = 150.0;
    const constant = 0.5;
    const result = analyzeSystem(a, b, c, constant);
    console.log(result);
}

main();