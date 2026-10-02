class FlightParameters {
    altitude: number;
    target: number;
    climb_rate: number;
    descent_rate: number;

    constructor(initial_altitude: number, target_altitude: number, max_climb_rate: number, descent_rate: number) {
        this.altitude = initial_altitude;
        this.target = target_altitude;
        this.climb_rate = max_climb_rate;
        this.descent_rate = descent_rate;
    }
}

class FlightControl {
    params: FlightParameters;

    constructor(parameters: FlightParameters) {
        this.params = parameters;
    }

    adjust_altitude(): number {
        if (this.params.altitude < this.params.target) {
            this.params.altitude += this.params.climb_rate;
        } else if (this.params.altitude > this.params.target) {
            this.params.altitude -= this.params.descent_rate;
        }
        return this.params.altitude;
    }
}

class FlightSimulation {
    control: FlightControl;
    is_operational: boolean;

    constructor(control: FlightControl) {
        this.control = control;
        this.is_operational = true;
    }

    run_simulation() {
        while (this.is_operational) {
            const new_altitude = this.control.adjust_altitude();
            if (new_altitude === this.control.params.target) {
                this.is_operational = false;
            }
            console.log(`Current Altitude: ${new_altitude}`);
        }
    }
}

function main() {
    const params = new FlightParameters(5000, 35000, 1500, 500);
    const control = new FlightControl(params);
    const simulation = new FlightSimulation(control);
    simulation.run_simulation();
}

main();