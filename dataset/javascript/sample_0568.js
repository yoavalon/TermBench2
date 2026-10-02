class Flight {
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

function boundary_check(flight, min_alt, max_alt) {
    if (flight.altitude < min_alt) {
        flight.update_altitude(min_alt);
    } else if (flight.altitude > max_alt) {
        flight.update_altitude(max_alt);
    }
}

function cruise_control(flight, target_speed) {
    if (flight.speed < target_speed) {
        flight.update_speed(flight.speed + 1);
    } else if (flight.speed > target_speed) {
        flight.update_speed(flight.speed - 1);
    }
}

function flight_simulation() {
    const flight = new Flight(10000, 500, 90);
    const min_altitude = 5000;
    const max_altitude = 30000;
    const target_speed = 600;
    while (true) {
        boundary_check(flight, min_altitude, max_altitude);
        cruise_control(flight, target_speed);
    }
}

function main() {
    flight_simulation();
}

main();