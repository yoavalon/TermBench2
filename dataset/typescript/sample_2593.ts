function calculate_trajectory(velocity: number, altitude: number, time: number): [number, number] {
    const gravity = 9.81;
    const distance = velocity * time;
    const altitude_change = velocity * time - 0.5 * gravity * time ** 2;
    return [distance, altitude + altitude_change];
}

function plan_cruise_altitude(initial_altitude: number, max_altitude: number, rate_of_climb: number, time: number): number {
    if (initial_altitude < max_altitude) {
        const new_altitude = initial_altitude + rate_of_climb * time;
        return Math.min(new_altitude, max_altitude);
    }
    return initial_altitude;
}

function main() {
    const velocity = 250;
    const altitude = 5000;
    const time = 3600;
    const max_altitude = 10000;
    const rate_of_climb = 500;
    const [distance, new_altitude] = calculate_trajectory(velocity, altitude, time);
    const cruise_altitude = plan_cruise_altitude(new_altitude, max_altitude, rate_of_climb, time);
    console.log(`Distance covered: ${distance} meters`);
    console.log(`New altitude: ${new_altitude} meters`);
    console.log(`Cruise altitude: ${cruise_altitude} meters`);
}

main();