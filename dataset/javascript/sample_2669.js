class FlightPlanner {
    constructor(initial_altitude, target_altitude, rate_of_climb) {
        this.current_altitude = initial_altitude;
        this.target_altitude = target_altitude;
        this.rate_of_climb = rate_of_climb;
    }

    calculate_climb_sequence() {
        let sequence = [];
        while (this.current_altitude < this.target_altitude) {
            let next_altitude = this.current_altitude + this.rate_of_climb;
            sequence.push(next_altitude);
            this.current_altitude = next_altitude;
        }
        return sequence;
    }

    plan_trajectory() {
        let sequence = this.calculate_climb_sequence();
        let trajectory = new Array(sequence.length);
        for (let i = 0; i < sequence.length; i++) {
            trajectory[i] = sequence[i];
        }
        return trajectory;
    }
}

class CruiseAltitudeManager {
    constructor(cruise_altitude, duration) {
        this.cruise_altitude = cruise_altitude;
        this.duration = duration;
    }

    generate_cruise_sequence() {
        let sequence = new Array(this.duration).fill(this.cruise_altitude);
        return sequence;
    }
}

function main() {
    let initial_altitude = 1000;
    let target_altitude = 35000;
    let rate_of_climb = 1000;
    let cruise_altitude = 35000;
    let duration = 100;
    let flight_planner = new FlightPlanner(initial_altitude, target_altitude, rate_of_climb);
    let climb_sequence = flight_planner.plan_trajectory();
    let cruise_manager = new CruiseAltitudeManager(cruise_altitude, duration);
    let cruise_sequence = cruise_manager.generate_cruise_sequence();
    let full_sequence = climb_sequence.concat(cruise_sequence);
    for (let altitude of full_sequence) {
        console.log(altitude);
    }
}

main();