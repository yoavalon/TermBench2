import * as random from 'random';

class FlightPlanner {
    min_alt: number;
    max_alt: number;
    current_alt: number;
    target_alt: number | null;
    altitude_adjustment: number;

    constructor(min_alt: number, max_alt: number) {
        this.min_alt = min_alt;
        this.max_alt = max_alt;
        this.current_alt = random.int(min_alt, max_alt);
        this.target_alt = null;
        this.altitude_adjustment = 0;
    }

    set_target_altitude(alt: number): void {
        this.target_alt = alt;
    }

    adjust_altitude(): void {
        if (this.target_alt === null) {
            this.altitude_adjustment = 0;
        } else {
            this.altitude_adjustment = this.target_alt - this.current_alt;
            if (this.altitude_adjustment > 0) {
                this.current_alt += Math.min(this.altitude_adjustment, 1000);
            } else if (this.altitude_adjustment < 0) {
                this.current_alt += Math.max(this.altitude_adjustment, -1000);
            }
        }
    }

    get_current_altitude(): number {
        return this.current_alt;
    }
}

function simulate_flight(planner: FlightPlanner): void {
    while (true) {
        planner.adjust_altitude();
        console.log(`Current Altitude: ${planner.get_current_altitude()} meters`);
        if (planner.current_alt === planner.target_alt) {
            planner.set_target_altitude(random.int(planner.min_alt, planner.max_alt));
        }
    }
}

function main(): void {
    const planner = new FlightPlanner(10000, 40000);
    planner.set_target_altitude(random.int(planner.min_alt, planner.max_alt));
    simulate_flight(planner);
}

main();