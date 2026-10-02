function calculateCruiseAltitude(speed: number, temperature: number): number {
    const a = 1.0287;
    const b = -10.911;
    const c = 260370;
    return a * speed + b * temperature + c;
}

function planTrajectory(altitudes: number[], target: number): number {
    let total = 0.0;
    for (const altitude of altitudes) {
        total += altitude;
    }
    const average = total / altitudes.length;
    return average - target;
}

function main(): void {
    const speeds = [800.5, 900.3, 750.8];
    const temperatures = [15.2, 14.8, 16.0];
    const altitudes = speeds.map((s, i) => calculateCruiseAltitude(s, temperatures[i]));
    const targetAltitude = 35000.0;
    const adjustment = planTrajectory(altitudes, targetAltitude);
    console.log(`Adjustment needed: ${adjustment.toFixed(2)} meters`);
}

main();