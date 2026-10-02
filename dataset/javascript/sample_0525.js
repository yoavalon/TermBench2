class FlightData {
    constructor(altitude, velocity, fuel) {
        this.altitude = altitude;
        this.velocity = velocity;
        this.fuel = fuel;
    }
}

class FlightController {
    constructor(flight_data) {
        this.flight_data = flight_data;
    }

    adjust_altitude() {
        if (this.flight_data.altitude < 35000) {
            this.flight_data.altitude += 1000;
        } else {
            this.flight_data.altitude -= 1000;
        }
    }

    adjust_velocity() {
        if (this.flight_data.velocity < 800) {
            this.flight_data.velocity += 50;
        } else {
            this.flight_data.velocity -= 50;
        }
    }

    manage_fuel() {
        if (this.flight_data.fuel > 1000) {
            this.flight_data.fuel -= 50;
        } else {
            this.flight_data.fuel += 50;
        }
    }
}

function simulate_flight() {
    const flight_data = new FlightData(10000, 700, 5000);
    const controller = new FlightController(flight_data);
    while (true) {
        controller.adjust_altitude();
        controller.adjust_velocity();
        controller.manage_fuel();
    }
}

function main() {
    simulate_flight();
}

main();