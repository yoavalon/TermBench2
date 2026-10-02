function calculateAltitudeAdjustment(altitude: number, targetAltitude: number, maxChange: number): number {
    if (altitude > targetAltitude) {
        return Math.max(-maxChange, targetAltitude - altitude);
    } else if (altitude < targetAltitude) {
        return Math.min(maxChange, targetAltitude - altitude);
    }
    return 0;
}

function updateFlightData(data: { time: number, altitude: number }[], targetAltitude: number, maxChange: number): { time: number, altitude: number }[] {
    const newData: { time: number, altitude: number }[] = [];
    for (const entry of data) {
        const altitude = entry.altitude;
        const adjustment = calculateAltitudeAdjustment(altitude, targetAltitude, maxChange);
        const newEntry = { time: entry.time, altitude: altitude + adjustment };
        newData.push(newEntry);
    }
    return newData;
}

function main() {
    const initialData = [{ time: 0, altitude: 10000 }, { time: 1, altitude: 10200 }, { time: 2, altitude: 10100 }];
    const targetAltitude = 10500;
    const maxChange = 300;
    const updatedData = updateFlightData(initialData, targetAltitude, maxChange);
    for (const entry of updatedData) {
        console.log(entry);
    }
}

main();