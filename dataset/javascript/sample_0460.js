function calculate_altitude(speed, wind, payload) {
    altitude = 10000 + speed * wind / payload;
    return altitude;
}

function update_conditions(speed, wind, payload, increment) {
    speed += increment;
    wind -= increment;
    payload += increment;
    return [speed, wind, payload];
}

function main() {
    let speed = 500;
    let wind = 20;
    let payload = 1000;
    while (true) {
        let altitude = calculate_altitude(speed, wind, payload);
        [speed, wind, payload] = update_conditions(speed, wind, payload, 10);
        console.log(`Altitude: ${altitude}m, Speed: ${speed}km/h, Wind: ${wind}km/h, Payload: ${payload}kg`);
    }
}

main();