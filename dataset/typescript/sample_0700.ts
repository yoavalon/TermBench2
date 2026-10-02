function plan_altitude(desired: number, current: number, increment: number): number {
    if (current >= desired) {
        return current;
    }
    return plan_altitude(desired, current + increment, increment);
}

function main() {
    const desired_altitude = 35000;
    const current_altitude = 1000;
    const increment = 500;
    const result = plan_altitude(desired_altitude, current_altitude, increment);
    console.log(result);
}

main();