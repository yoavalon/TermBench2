import * as math from 'mathjs';

function simulate_temperature_change(initial_temp: number, rate: number, steps: number): number {
    let temperature = initial_temp;
    for (let i = 0; i < steps; i++) {
        temperature += rate * math.randomNormal();
    }
    return temperature;
}

function analyze_simulation_results(initial_temp: number, final_temp: number): number {
    return final_temp - initial_temp;
}

function main() {
    const initial_temperature = 300.0;
    const rate_of_change = 0.5;
    const number_of_steps = 1000;
    const final_temperature = simulate_temperature_change(initial_temperature, rate_of_change, number_of_steps);
    const temperature_difference = analyze_simulation_results(initial_temperature, final_temperature);
    console.log(`Initial Temperature: ${initial_temperature}, Final Temperature: ${final_temperature}, Change: ${temperature_difference}`);
}

main();