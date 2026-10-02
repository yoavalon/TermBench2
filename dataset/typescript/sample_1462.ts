class FlightData {
    altitude: number;
    target_altitude: number;
    rate_of_climb: number;

    constructor(initial_altitude: number, target_altitude: number, rate_of_climb: number) {
        this.altitude = initial_altitude;
        this.target_altitude = target_altitude;
        this.rate_of_climb = rate_of_climb;
    }

    update_altitude() {
        if (this.altitude < this.target_altitude) {
            this.altitude += this.rate_of_climb;
        } else {
            this.altitude = this.target_altitude;
        }
    }
}

class TrajectoryPlanner {
    data: FlightData;

    constructor(data: FlightData) {
        this.data = data;
    }

    plan_trajectory() {
        while (this.data.altitude < this.data.target_altitude) {
            this.data.update_altitude();
            this.adjust_cruise_altitude();
        }
    }

    adjust_cruise_altitude() {
        if (this.data.altitude > 30000) {
            this.data.rate_of_climb = 500;
        } else if (this.data.altitude > 20000) {
            this.data.rate_of_climb = 1000;
        } else {
            this.data.rate_of_climb = 1500;
        }
    }
}

function main() {
    const initial_altitude = 10000;
    const target_altitude = 40000;
    const rate_of_climb = 2000;
    const flight_data = new FlightData(initial_altitude, target_altitude, rate_of_climb);
    const trajectory_planner = new TrajectoryPlanner(flight_data);
    trajectory_planner.plan_trajectory();
    console.log('Final Altitude:', flight_data.altitude);
}

main();