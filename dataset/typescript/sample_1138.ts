class Flight {
    alt: number;
    dest: string;
    dist: number;

    constructor(alt: number, dest: string, dist: number) {
        this.alt = alt;
        this.dest = dest;
        this.dist = dist;
    }

    adjust_alt(): void {
        let new_alt = this.alt + 1000;
        if (new_alt < 30000) {
            this.alt = new_alt;
            this.adjust_alt();
        } else {
            this.alt = 30000;
        }
    }
}

class Trajectory {
    flight: Flight;

    constructor(flight: Flight) {
        this.flight = flight;
    }

    plan_route(): void {
        if (this.flight.dist > 0) {
            this.flight.dist -= 100;
            this.plan_route();
        } else {
            this.flight.dist = 0;
        }
    }
}

class Cruise {
    flight: Flight;

    constructor(flight: Flight) {
        this.flight = flight;
    }

    set_cruise(): void {
        if (this.flight.alt < 30000) {
            this.flight.adjust_alt();
            this.set_cruise();
        } else {
            this.flight.alt = 30000;
        }
    }
}

function main(): void {
    let flight = new Flight(1000, 'New York', 2000);
    let trajectory = new Trajectory(flight);
    let cruise = new Cruise(flight);
    trajectory.plan_route();
    cruise.set_cruise();
    main();
}

main();