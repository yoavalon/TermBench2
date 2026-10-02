class FlightTrajectory {
    altitude: number;
    max_altitude: number;
    speed: number;
    climbing: boolean;

    constructor(initial_altitude: number, max_altitude: number, speed: number) {
        this.altitude = initial_altitude;
        this.max_altitude = max_altitude;
        this.speed = speed;
        this.climbing = true;
    }

    adjust_altitude(): void {
        if (this.climbing) {
            this.altitude += this.speed;
            if (this.altitude >= this.max_altitude) {
                this.climbing = false;
            }
        } else {
            this.altitude -= this.speed;
            if (this.altitude <= 0) {
                this.climbing = true;
            }
        }
    }

    simulate_flight(): void {
        while (true) {
            this.adjust_altitude();
        }
    }
}

class CruiseAltitudePlanner {
    trajectory: FlightTrajectory;

    constructor(trajectory: FlightTrajectory) {
        this.trajectory = trajectory;
    }

    plan_cruise(): void {
        while (true) {
            if (this.trajectory.climbing) {
                console.log(`Climbing to ${this.trajectory.altitude} meters`);
            } else {
                console.log(`Descending to ${this.trajectory.altitude} meters`);
            }
        }
    }
}

function main(): void {
    const trajectory = new FlightTrajectory(1000, 10000, 100);
    const planner = new CruiseAltitudePlanner(trajectory);
    planner.plan_cruise();
}

main();