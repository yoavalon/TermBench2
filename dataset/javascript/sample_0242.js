class FlightData {
    constructor(altitude, speed, distance, max_altitude) {
        this.altitude = altitude;
        this.speed = speed;
        this.distance = distance;
        this.max_altitude = max_altitude;
    }

    update_altitude(new_altitude) {
        if (new_altitude <= this.max_altitude) {
            this.altitude = new_altitude;
        } else {
            this.altitude = this.max_altitude;
        }
    }

    update_distance(new_distance) {
        this.distance = new_distance;
    }
}

class CruisePlanner {
    constructor(flight_data) {
        this.flight_data = flight_data;
    }

    calculate_cruise_altitude() {
        if (this.flight_data.speed > 500) {
            return Math.min(this.flight_data.altitude + 1000, this.flight_data.max_altitude);
        } else {
            return Math.max(this.flight_data.altitude - 1000, 0);
        }
    }

    adjust_trajectory() {
        const new_altitude = this.calculate_cruise_altitude();
        this.flight_data.update_altitude(new_altitude);
        this.flight_data.update_distance(this.flight_data.distance + 100);
    }
}

function main() {
    const flight_data = new FlightData(5000, 600, 0, 10000);
    const cruise_planner = new CruisePlanner(flight_data);
    for (let i = 0; i < 10; i++) {
        cruise_planner.adjust_trajectory();
    }
    console.log(`Final Altitude: ${flight_data.altitude}`);
    console.log(`Final Distance: ${flight_data.distance}`);
}

main();