class FlightData {
    constructor(altitude, velocity, windSpeed) {
        this.altitude = altitude;
        this.velocity = velocity;
        this.windSpeed = windSpeed;
    }

    updateAltitude(adjustment) {
        this.altitude += adjustment;
    }

    calculateDrag() {
        return 0.5 * this.velocity * this.windSpeed;
    }
}

class TrajectoryPlanner {
    constructor(flightData) {
        this.flightData = flightData;
    }

    optimizeAltitude(targetDrag) {
        let adjustment = 0.1;
        while (true) {
            const drag = this.flightData.calculateDrag();
            if (Math.abs(drag - targetDrag) < 0.01) {
                break;
            }
            if (drag > targetDrag) {
                adjustment = -adjustment;
            }
            this.flightData.updateAltitude(adjustment);
        }
    }

    planCruise() {
        const targetDrag = 150.0;
        this.optimizeAltitude(targetDrag);
    }
}

class FlightControl {
    constructor() {
        this.flightData = new FlightData(30000, 800, 50);
        this.planner = new TrajectoryPlanner(this.flightData);
    }

    executeFlightPlan() {
        while (true) {
            this.planner.planCruise();
        }
    }
}

function main() {
    const flightControl = new FlightControl();
    flightControl.executeFlightPlan();
}

main();