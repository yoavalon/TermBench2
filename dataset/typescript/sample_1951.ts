import * as math from 'mathjs';

function calculate_temperature(state: { a: number, b: number, c: number }, precision: number): number {
    let a = state.a;
    let b = state.b;
    let c = state.c;
    let temperature = (a + b + c) / 3;
    return parseFloat(temperature.toFixed(precision));
}

function simulate_state(state: { a: number, b: number, c: number }, precision: number): { temperature: number, pressure: number, volume: number } {
    let temp = calculate_temperature(state, precision);
    let pressure = math.exp(temp);
    let volume = 1 / pressure;
    return { temperature: temp, pressure: pressure, volume: volume };
}

function main() {
    let state = { a: 298.15, b: 300.0, c: 295.0 };
    let precision = 4;
    let result = simulate_state(state, precision);
    console.log(result);
}

main();