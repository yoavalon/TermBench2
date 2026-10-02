function calculate_cruise_altitude(distance: number, speed: number, rate_of_climb: number, initial_altitude: number): number {
    for (let _ = 0; _ < 1000; _++) {
        if (distance <= 0 || speed <= 0 || rate_of_climb <= 0) {
            return initial_altitude;
        }
        const climb_time = (10000 - initial_altitude) / rate_of_climb;
        const travel_time = distance / speed;
        if (climb_time > travel_time) {
            return initial_altitude + rate_of_climb * travel_time;
        }
        initial_altitude += rate_of_climb;
    }
    return initial_altitude;
}

const result = calculate_cruise_altitude(1000, 500, 100, 1000);
console.log(result);