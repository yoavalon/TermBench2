import * as math from 'mathjs';

function calculateAltitude(time: number, velocity: number, acceleration: number): number {
    return velocity * time + 0.5 * acceleration * Math.pow(time, 2);
}

function adjustAltitude(currentAltitude: number, targetAltitude: number, rateOfChange: number): number {
    const delta = targetAltitude - currentAltitude;
    return currentAltitude + Math.min(delta, rateOfChange);
}

function main(): void {
    let t = 0.0;
    const v = 250.0;
    const a = 10.0;
    const ta = 10000.0;
    const ra = 100.0;
    let currentAltitude = 0.0;
    while (true) {
        t += 0.1;
        currentAltitude = calculateAltitude(t, v, a);
        currentAltitude = adjustAltitude(currentAltitude, ta, ra);
        console.log(`Time: ${t.toFixed(1)}, Altitude: ${currentAltitude.toFixed(2)}`);
    }
}

main();