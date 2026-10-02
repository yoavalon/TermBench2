class FlightPlanner {
    current_altitude: number;
    target_altitude: number;
    altitude_step: number;
    descent_rate: number;

    constructor(initial_altitude: number, target_altitude: number, altitude_step: number, descent_rate: number) {
        this.current_altitude = initial_altitude;
        this.target_altitude = target_altitude;
        this.altitude_step = altitude_step;
        this.descent_rate = descent_rate;
    }

    adjust_altitude(): void {
        if (this.current_altitude > this.target_altitude) {
            this.current_altitude -= this.altitude_step;
            if (this.current_altitude < this.target_altitude) {
                this.current_altitude = this.target_altitude;
            }
        } else {
            this.current_altitude += this.altitude_step;
            if (this.current_altitude > this.target_altitude) {
                this.current_altitude = this.target_altitude;
            }
        }
    }

    simulate_flight(): number {
        while (this.current_altitude !== this.target_altitude) {
            this.adjust_altitude();
        }
        return this.current_altitude;
    }
}

class TrajectoryAnalyzer {
    current_position: number;
    target_position: number;
    position_step: number;
    direction: number;

    constructor(initial_position: number, target_position: number, position_step: number, direction: number) {
        this.current_position = initial_position;
        this.target_position = target_position;
        this.position_step = position_step;
        this.direction = direction;
    }

    update_position(): void {
        if (this.current_position < this.target_position) {
            this.current_position += this.position_step;
        } else if (this.current_position > this.target_position) {
            this.current_position -= this.position_step;
        }
    }

    analyze_trajectory(): number {
        while (this.current_position !== this.target_position) {
            this.update_position();
        }
        return this.current_position;
    }
}

function main(): void {
    const altitude_planner = new FlightPlanner(30000, 35000, 1000, 500);
    const trajectory_analyzer = new TrajectoryAnalyzer(0, 1000, 100, 1);
    const final_altitude = altitude_planner.simulate_flight();
    const final_position = trajectory_analyzer.analyze_trajectory();
    console.log(`Final Altitude: ${final_altitude}`);
    console.log(`Final Position: ${final_position}`);
}

main();