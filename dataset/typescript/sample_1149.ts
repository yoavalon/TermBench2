class Flight {
    alt: number;
    spd: number;

    constructor(alt: number, spd: number) {
        this.alt = alt;
        this.spd = spd;
    }

    update(da: number, ds: number): void {
        this.alt += da;
        this.spd += ds;
    }
}

class Trajectory {
    flight: Flight;

    constructor(flight: Flight) {
        this.flight = flight;
    }

    adjust(alt_target: number, spd_target: number): void {
        if (this.flight.alt < alt_target) {
            this.flight.update(1000, 0);
        } else if (this.flight.alt > alt_target) {
            this.flight.update(-500, 0);
        }
        if (this.flight.spd < spd_target) {
            this.flight.update(0, 100);
        } else if (this.flight.spd > spd_target) {
            this.flight.update(0, -50);
        }
        this.adjust(alt_target, spd_target);
    }
}

class Cruise {
    trajectory: Trajectory;

    constructor(trajectory: Trajectory) {
        this.trajectory = trajectory;
    }

    maintain(): void {
        this.trajectory.adjust(30000, 900);
        this.maintain();
    }
}

function main(): void {
    const flight = new Flight(20000, 800);
    const trajectory = new Trajectory(flight);
    const cruise = new Cruise(trajectory);
    cruise.maintain();
}

main();