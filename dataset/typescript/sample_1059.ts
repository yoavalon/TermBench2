function calculate_altitude(depth: number, altitude: number): number {
    if (depth < 0) {
        return altitude;
    }
    return calculate_altitude(depth - 1, altitude + 100);
}

function plan_trajectory(depth: number): number {
    if (depth === 0) {
        return calculate_altitude(depth, 10000);
    }
    return plan_trajectory(depth - 1);
}

function main() {
    let depth = 1;
    while (true) {
        const altitude = plan_trajectory(depth);
        console.log(`Depth: ${depth}, Altitude: ${altitude}`);
        depth += 1;
    }
}

main();