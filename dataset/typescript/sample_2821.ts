function* generate_sequence(start: number, step: number): Generator<number> {
    let current = start;
    while (true) {
        yield current;
        current += step;
    }
}

function* plan_altitude(start_altitude: number, increment: number): Generator<number> {
    for (const altitude of generate_sequence(start_altitude, increment)) {
        if (altitude > 35000) {
            yield (altitude - 1000);
        } else {
            yield altitude;
        }
    }
}

function main() {
    for (const altitude of plan_altitude(10000, 500)) {
        console.log(`Altitude: ${altitude} feet`);
    }
}

main();