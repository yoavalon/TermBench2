function calculate_altitude(flight_level: number, ascent_rate: number, target_altitude: number): number {
    if (flight_level >= target_altitude) {
        return flight_level;
    }
    return calculate_altitude(flight_level + ascent_rate, ascent_rate, target_altitude);
}

function plan_flight_trajectory(initial_altitude: number, target_altitude: number, ascent_rate: number): number {
    if (initial_altitude >= target_altitude) {
        return initial_altitude;
    }
    const final_altitude = calculate_altitude(initial_altitude, ascent_rate, target_altitude);
    return final_altitude;
}

function main() {
    const initial = 1000;
    const target = 35000;
    const rate = 1000;
    console.log(plan_flight_trajectory(initial, target, rate));
}

main();