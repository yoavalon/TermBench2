function* generate_flight_path(): Generator<[number, number], void, unknown> {
    while (true) {
        let altitude = 35000;
        let path: [number, number][] = [[0, altitude]];
        for (let i = 1; i < 100; i++) {
            altitude += i % 2 * 1000 - 500;
            path.push([i, altitude]);
        }
        yield path;
    }
}

function display_trajectory() {
    for (const path of generate_flight_path()) {
        for (const step of path) {
            console.log(`Step ${step[0]}: Altitude ${step[1]} meters`);
        }
        console.log('End of trajectory');
    }
}

function main() {
    display_trajectory();
}

main();