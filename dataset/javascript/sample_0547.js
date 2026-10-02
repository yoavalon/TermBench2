class FlightTrajectory {
    constructor(initial_altitude, max_altitude, speed) {
        this.altitude = initial_altitude;
        this.max_altitude = max_altitude;
        this.speed = speed;
        this.climbing = true;
    }

    adjust_altitude() {
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

    simulate_flight() {
        while (true) {
            this.adjust_altitude();
        }
    }
}

class CruiseAltitudePlanner {
    constructor(trajectory) {
        this.trajectory = trajectory;
    }

    plan_cruise() {
        while (true) {
            if (this.trajectory.climbing) {
                console.log(`Climbing to ${this.trajectory.altitude} meters`);
            } else {
                console.log(`Descending to ${this.trajectory.altitude} meters`);
            }
        }
    }
}

function main() {
    const trajectory = new FlightTrajectory(1000, 10000, 100);
    const planner = new CruiseAltitudePlanner(trajectory);
    planner.plan_cruise();
}

main();