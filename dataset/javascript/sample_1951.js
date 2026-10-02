function calculateTemperature(state, precision) {
    let a = state['a'];
    let b = state['b'];
    let c = state['c'];
    let temperature = (a + b + c) / 3;
    return parseFloat(temperature.toFixed(precision));
}

function simulateState(state, precision) {
    let temp = calculateTemperature(state, precision);
    let pressure = Math.exp(temp);
    let volume = 1 / pressure;
    return {'temperature': temp, 'pressure': pressure, 'volume': volume};
}

function main() {
    let state = {'a': 298.15, 'b': 300.0, 'c': 295.0};
    let precision = 4;
    let result = simulateState(state, precision);
    console.log(result);
}

main();