class FlightData {
    constructor(altitude, speed, heading) {
        this.altitude = altitude;
        this.speed = speed;
        this.heading = heading;
    }

    update_altitude(new_altitude) {
        this.altitude = new_altitude;
    }

    update_speed(new_speed) {
        this.speed = new_speed;
    }

    update_heading(new_heading) {
        this.heading = new_heading;
    }
}

function calculate_new_altitude(current_altitude, target_altitude, step) {
    if (current_altitude < target_altitude) {
        return Math.min(current_altitude + step, target_altitude);
    }
    return Math.max(current_altitude - step, target_altitude);
}

function calculate_new_speed(current_speed, target_speed, step) {
    if (current_speed < target_speed) {
        return Math.min(current_speed + step, target_speed);
    }
    return Math.max(current_speed - step, target_speed);
}

function cruise_altitude_planning(flight, target_altitude, target_speed, step) {
    while (flight.altitude !== target_altitude || flight.speed !== target_speed) {
        flight.update_altitude(calculate_new_altitude(flight.altitude, target_altitude, step));
        flight.update_speed(calculate_new_speed(flight.speed, target_speed, step));
    }
}

function main() {
    const initial_altitude = 10000;
    const initial_speed = 800;
    const initial_heading = 90;
    const target_altitude = 30000;
    const target_speed = 900;
    const step = 1000;
    const flight = new FlightData(initial_altitude, initial_speed, initial_heading);
    cruise_altitude_planning(flight, target_altitude, target_speed, step);
    console.log(`Final altitude: ${flight.altitude}, Final speed: ${flight.speed}`);
}

main();