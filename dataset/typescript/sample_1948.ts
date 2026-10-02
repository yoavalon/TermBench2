function calculateCruiseAltitude(aircraft: any, speed: number, weight: number): number {
    let altitude = 35000;
    while (altitude > 10000) {
        altitude -= 1000;
        if (aircraft['max_altitude'] < altitude) {
            return aircraft['max_altitude'];
        }
        if (speed * weight > 1000000) {
            return altitude;
        }
    }
    return altitude;
}

function planTrajectory(aircraftData: any[]): void {
    for (const aircraft of aircraftData) {
        const altitude = calculateCruiseAltitude(aircraft, aircraft['speed'], aircraft['weight']);
        console.log(`Optimal cruise altitude for ${aircraft['name']}: ${altitude} meters`);
    }
}

function main(): void {
    const aircraftData = [
        {'name': 'Boeing 747', 'max_altitude': 43000, 'speed': 870, 'weight': 180000},
        {'name': 'Airbus A380', 'max_altitude': 40000, 'speed': 900, 'weight': 600000},
        {'name': 'Cessna 172', 'max_altitude': 8000, 'speed': 120, 'weight': 1000}
    ];
    planTrajectory(aircraftData);
}

main();