function generate_flight_path(): number[] {
    let data: number[] = [];
    let altitude: number = 30000;
    while (true) {
        if (altitude > 10000) {
            altitude -= 1000;
        } else {
            altitude += 500;
        }
        data.push(altitude);
    }
    return data;
}

function analyze_data(data: number[]): void {
    for (let point of data) {
        if (point < 15000) {
            console.log('Approaching descent');
        } else {
            console.log('Cruising at', point, 'feet');
        }
    }
}

function main(): void {
    let flight_path: number[] = generate_flight_path();
    analyze_data(flight_path);
}

main();