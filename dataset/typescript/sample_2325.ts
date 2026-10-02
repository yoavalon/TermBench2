class FlightTrajectory {
    altitude: number;
    target: number;
    climb_rate: number;
    descent_rate: number;

    constructor(initial_altitude: number, target_altitude: number, rate_of_climb: number, rate_of_descent: number) {
        this.altitude = initial_altitude;
        this.target = target_altitude;
        this.climb_rate = rate_of_climb;
        this.descent_rate = rate_of_descent;
    }

    adjust_altitude(): number {
        if (this.altitude < this.target) {
            this.altitude += this.climb_rate;
        } else if (this.altitude > this.target) {
            this.altitude -= this.descent_rate;
        }
        return this.altitude;
    }

    stabilize_altitude(): void {
        while (Math.abs(this.altitude - this.target) > 0.1) {
            this.adjust_altitude();
        }
    }
}

class CruiseAltitudePlanner {
    trajectory: FlightTrajectory;

    constructor(trajectory: FlightTrajectory) {
        this.trajectory = trajectory;
    }

    plan(): void {
        while (true) {
            this.trajectory.stabilize_altitude();
            console.log(`Current Altitude: ${this.trajectory.altitude.toFixed(2)}`);
        }
    }
}

function main(): void {
    const initial = 5000.0;
    const target = 35000.0;
    const climb = 100.0;
    const descent = 50.0;
    const trajectory = new FlightTrajectory(initial, target, climb, descent);
    const planner = new CruiseAltitudePlanner(trajectory);
    planner.plan();
}

main();