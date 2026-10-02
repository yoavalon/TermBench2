class FlightParameters {
    altitude: number;
    cruise_altitude: number;
    rate_of_climb: number;
    rate_of_descent: number;

    constructor(initial_altitude: number, cruise_altitude: number, rate_of_climb: number, rate_of_descent: number) {
        this.altitude = initial_altitude;
        this.cruise_altitude = cruise_altitude;
        this.rate_of_climb = rate_of_climb;
        this.rate_of_descent = rate_of_descent;
    }

    update_altitude(action: string): void {
        if (action === 'climb') {
            this.altitude += this.rate_of_climb;
        } else if (action === 'descend') {
            this.altitude -= this.rate_of_descent;
        }
    }

    is_at_cruise(): boolean {
        return this.altitude >= this.cruise_altitude;
    }
}

class BoundaryConditions {
    min_altitude: number;
    max_altitude: number;

    constructor(min_altitude: number, max_altitude: number) {
        this.min_altitude = min_altitude;
        this.max_altitude = max_altitude;
    }

    is_within_bounds(altitude: number): boolean {
        return this.min_altitude <= altitude && altitude <= this.max_altitude;
    }

    adjust_boundary(altitude: number): number {
        if (altitude < this.min_altitude) {
            return this.min_altitude;
        } else if (altitude > this.max_altitude) {
            return this.max_altitude;
        }
        return altitude;
    }
}

function flight_control_system(flight: FlightParameters, boundaries: BoundaryConditions): void {
    while (true) {
        if (!boundaries.is_within_bounds(flight.altitude)) {
            flight.altitude = boundaries.adjust_boundary(flight.altitude);
        }
        if (!flight.is_at_cruise()) {
            const action = flight.altitude < flight.cruise_altitude ? 'climb' : 'descend';
            flight.update_altitude(action);
        }
    }
}

function main(): void {
    const flight = new FlightParameters(5000, 35000, 1000, 500);
    const boundaries = new BoundaryConditions(5000, 40000);
    flight_control_system(flight, boundaries);
}

main();