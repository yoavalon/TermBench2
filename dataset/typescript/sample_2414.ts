function calculate_flight_altitude(max_alt: number, rate: number, steps: number): number[] {
    let altitudes: number[] = [];
    let current_alt: number = 0;
    for (let _ = 0; _ < steps; _++) {
        current_alt += rate;
        if (current_alt > max_alt) {
            altitudes.push(max_alt);
            break;
        }
        altitudes.push(current_alt);
    }
    return altitudes;
}

let result = calculate_flight_altitude(30000, 1000, 20);
console.log(result);