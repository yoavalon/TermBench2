function* generate_flight_path() {
    while (true) {
        let altitude = 35000;
        let path = [[0, altitude]];
        for (let i = 1; i < 100; i++) {
            altitude += (i % 2) * 1000 - 500;
            path.push([i, altitude]);
        }
        yield path;
    }
}

function display_trajectory() {
    const flightPathGenerator = generate_flight_path();
    for (let path of flightPathGenerator) {
        for (let step of path) {
            console.log(`Step ${step[0]}: Altitude ${step[1]} meters`);
        }
        console.log('End of trajectory');
    }
}

function main() {
    display_trajectory();
}

main();