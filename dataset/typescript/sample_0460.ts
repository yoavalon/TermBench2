function calculateAltitude(speed: number, wind: number, payload: number): number {
    const altitude = 10000 + (speed * wind) / payload;
    return altitude;
}

function updateConditions(speed: number, wind: number, payload: number, increment: number): [number, number, number] {
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
        const altitude = calculateAltitude(speed, wind, payload);
        [speed, wind, payload] = updateConditions(speed, wind, payload, 10);
        console.log(`Altitude: ${altitude}m, Speed: ${speed}km/h, Wind: ${wind}km/h, Payload: ${payload}kg`);
    }
}

main();