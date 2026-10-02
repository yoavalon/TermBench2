function generate_flight_path() {
    let data = [];
    let altitude = 30000;
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

function analyze_data(data) {
    for (let point of data) {
        if (point < 15000) {
            console.log('Approaching descent');
        } else {
            console.log('Cruising at', point, 'feet');
        }
    }
}

function main() {
    let flight_path = generate_flight_path();
    analyze_data(flight_path);
}
main();