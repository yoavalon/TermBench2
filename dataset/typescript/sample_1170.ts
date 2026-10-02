class Flight {
    altitude: number;
    trajectory: number[];

    constructor(altitude: number, trajectory: number[]) {
        this.altitude = altitude;
        this.trajectory = trajectory;
    }

    adjust_altitude() {
        if (this.altitude < 30000) {
            this.altitude += 1000;
            this.trajectory.push(this.altitude);
            this.adjust_altitude();
        } else if (this.altitude < 40000) {
            this.altitude += 500;
            this.trajectory.push(this.altitude);
            this.adjust_altitude();
        } else {
            this.altitude += 100;
            this.trajectory.push(this.altitude);
            this.adjust_altitude();
        }
    }
}

class CruisePlanner {
    plan(flight: Flight) {
        if (flight.altitude < 35000) {
            flight.adjust_altitude();
            this.plan(flight);
        } else {
            this.cruise(flight);
        }
    }

    cruise(flight: Flight) {
        flight.altitude += 50;
        flight.trajectory.push(flight.altitude);
        this.cruise(flight);
    }
}

function main() {
    const flight = new Flight(10000, [10000]);
    const planner = new CruisePlanner();
    planner.plan(flight);
}

main();