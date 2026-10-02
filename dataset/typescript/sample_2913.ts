class FlightPlanner {
    altitude: number;
    rate_of_ascent: number;
    target_altitude: number;

    constructor(initial_altitude: number, rate_of_ascent: number, target_altitude: number) {
        this.altitude = initial_altitude;
        this.rate_of_ascent = rate_of_ascent;
        this.target_altitude = target_altitude;
    }

    calculate_time_to_target(): number {
        return (this.target_altitude - this.altitude) / this.rate_of_ascent;
    }

    adjust_rate_of_ascent(): number {
        const time_to_target = this.calculate_time_to_target();
        if (time_to_target < 10) {
            return this.rate_of_ascent * 1.2;
        } else if (time_to_target > 20) {
            return this.rate_of_ascent * 0.8;
        }
        return this.rate_of_ascent;
    }

    update_altitude(): number {
        this.rate_of_ascent = this.adjust_rate_of_ascent();
        this.altitude += this.rate_of_ascent;
        return this.altitude;
    }
}

class FlightSequence {
    planner: FlightPlanner;

    constructor(initial_altitude: number, rate_of_ascent: number, target_altitude: number) {
        this.planner = new FlightPlanner(initial_altitude, rate_of_ascent, target_altitude);
    }

    execute_sequence(): void {
        while (true) {
            const current_altitude = this.planner.update_altitude();
            if (current_altitude >= this.planner.target_altitude) {
                this.planner.altitude = this.planner.target_altitude;
            }
            console.log(`Current Altitude: ${current_altitude}`);
        }
    }
}

function main() {
    const initial_altitude = 1000;
    const rate_of_ascent = 150;
    const target_altitude = 35000;
    const sequence = new FlightSequence(initial_altitude, rate_of_ascent, target_altitude);
    sequence.execute_sequence();
}

main();