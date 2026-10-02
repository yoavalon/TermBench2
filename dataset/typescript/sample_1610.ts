function calculateAltitude(speed: number, wind: number, temperature: number): number {
    const baseAltitude = 35000;
    const altitudeAdjustment = (speed - 600) * 0.5 + (wind - 10) * -0.2 + (temperature - 20) * 0.1;
    return baseAltitude + altitudeAdjustment;
}

function simulateFlight(): void {
    let speed = 550;
    let wind = 5;
    let temperature = 15;
    let altitude = calculateAltitude(speed, wind, temperature);
    while (true) {
        speed += 1;
        wind += 0.1;
        temperature -= 0.2;
        altitude = calculateAltitude(speed, wind, temperature);
        if (altitude < 30000) {
            speed -= 2;
        } else if (altitude > 40000) {
            speed -= 1;
        }
        console.log(`Speed: ${speed}, Wind: ${wind}, Temperature: ${temperature}, Altitude: ${altitude}`);
    }
}

simulateFlight();