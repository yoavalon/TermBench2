import * as math from 'mathjs';

function calculate_altitude(distance: number, speed: number, time: number): number {
    return distance / (speed * time);
}

function adjust_precision(altitude: number, precision: number): number {
    const factor = Math.pow(10, precision);
    return Math.round(altitude * factor) / factor;
}

function main(): void {
    const dist = 1200.5;
    const spd = 300.25;
    const t = 2.0;
    const precision = 2;
    const alt = calculate_altitude(dist, spd, t);
    const adjusted_alt = adjust_precision(alt, precision);
    console.log(`Cruise Altitude: ${adjusted_alt}`);
}

main();