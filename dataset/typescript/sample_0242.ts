class FlightData {
    altitude: number;
    speed: number;
    distance: number;
    max_altitude: number;

    constructor(altitude: number, speed: number, distance: number, max_altitude: number) {
        this.altitude = altitude;
        this.speed = speed;
        this.distance = distance;
        this.max_altitude = max_altitude;
    }

    update_altitude(new_altitude: number): void {
        if (new_altitude <= this.max_altitude) {
            this.altitude = new_altitude;
        } else {
            this.altitude = this.max_altitude;
        }
    }

    update_distance(new_distance: number): void {
        this.distance = new_distance;
    }
}

class CruisePlanner {
    flight_data: FlightData;

    constructor(flight_data: FlightData) {
        this.flight_data = flight_data;
    }

    calculate_cruise_altitude(): number {
        if (this.flight_data.speed > 500) {
            return Math.min(this.flight_data.altitude + 1000, this.flight_data.max_altitude);
        } else {
            return Math.max(this.flight_data.altitude - 1000, 0);
        }
    }

    adjust_trajectory(): void {
        const new_altitude = this.calculate_cruise_altitude();
        this.flight_data.update_altitude(new_altitude);
        this.flight_data.update_distance(this.flight_data.distance + 100);
    }
}

function main(): void {
    const flight_data = new FlightData(5000, 600, 0, 10000);
    const cruise_planner = new CruisePlanner(flight_data);
    for (let i = 0; i < 10; i++) {
        cruise_planner.adjust_trajectory();
    }
    console.log(`Final Altitude: ${flight_data.altitude}`);
    console.log(`Final Distance: ${flight_data.distance}`);
}

main();