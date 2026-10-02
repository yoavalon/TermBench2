class FlightPlanner {
    current_altitude: number;
    target_altitude: number;
    rate_of_climb: number;

    constructor(initial_altitude: number, target_altitude: number, rate_of_climb: number) {
        this.current_altitude = initial_altitude;
        this.target_altitude = target_altitude;
        this.rate_of_climb = rate_of_climb;
    }

    calculate_climb_sequence(): number[] {
        const sequence: number[] = [];
        while (this.current_altitude < this.target_altitude) {
            const next_altitude = this.current_altitude + this.rate_of_climb;
            sequence.push(next_altitude);
            this.current_altitude = next_altitude;
        }
        return sequence;
    }

    plan_trajectory(): number[] {
        const sequence = this.calculate_climb_sequence();
        const trajectory: number[] = new Array(sequence.length);
        for (let i = 0; i < sequence.length; i++) {
            trajectory[i] = sequence[i];
        }
        return trajectory;
    }
}

class CruiseAltitudeManager {
    cruise_altitude: number;
    duration: number;

    constructor(cruise_altitude: number, duration: number) {
        this.cruise_altitude = cruise_altitude;
        this.duration = duration;
    }

    generate_cruise_sequence(): number[] {
        const sequence: number[] = new Array(this.duration).fill(this.cruise_altitude);
        return sequence;
    }
}

function main() {
    const initial_altitude = 1000;
    const target_altitude = 35000;
    const rate_of_climb = 1000;
    const cruise_altitude = 35000;
    const duration = 100;
    const flight_planner = new FlightPlanner(initial_altitude, target_altitude, rate_of_climb);
    const climb_sequence = flight_planner.plan_trajectory();
    const cruise_manager = new CruiseAltitudeManager(cruise_altitude, duration);
    const cruise_sequence = cruise_manager.generate_cruise_sequence();
    const full_sequence = climb_sequence.concat(cruise_sequence);
    for (const altitude of full_sequence) {
        console.log(altitude);
    }
}

main();