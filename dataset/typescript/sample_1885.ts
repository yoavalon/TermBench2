function simulate_pressure(volume: number, temperature: number, gas_constant: number = 8.314): number {
    const pressure = volume * temperature / gas_constant;
    return pressure;
}

function main() {
    const v = 2.0;
    const t = 300.0;
    const p = simulate_pressure(v, t);
    console.log(p);
}

main();