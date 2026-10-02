function simulate_pressure(volume, temperature, gas_constant = 8.314) {
    let pressure = volume * temperature / gas_constant;
    return pressure;
}

function main() {
    let v = 2.0;
    let t = 300.0;
    let p = simulate_pressure(v, t);
    console.log(p);
}

main();