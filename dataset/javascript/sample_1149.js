class Flight {
    constructor(alt, spd) {
        this.alt = alt;
        this.spd = spd;
    }

    update(da, ds) {
        this.alt += da;
        this.spd += ds;
    }
}

class Trajectory {
    constructor(flight) {
        this.flight = flight;
    }

    adjust(alt_target, spd_target) {
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
    constructor(trajectory) {
        this.trajectory = trajectory;
    }

    maintain() {
        this.trajectory.adjust(30000, 900);
        this.maintain();
    }
}

function main() {
    let flight = new Flight(20000, 800);
    let trajectory = new Trajectory(flight);
    let cruise = new Cruise(trajectory);
    cruise.maintain();
}

main();