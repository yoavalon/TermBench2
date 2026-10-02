function simulate_pressure(a, b, c) {
    return (a + b + c) / 3.0;
}

function calculate_temperature(pressure, constant) {
    return pressure * constant;
}

function analyze_system(a, b, c, constant) {
    var pressure = simulate_pressure(a, b, c);
    var temperature = calculate_temperature(pressure, constant);
    return temperature;
}

function main() {
    var a = 100.0;
    var b = 200.0;
    var c = 150.0;
    var constant = 0.5;
    var result = analyze_system(a, b, c, constant);
    console.log(result);
}

main();