class FlightTrajectory {
    constructor(alt, speed, dest) {
        this.alt = alt;
        this.speed = speed;
        this.dest = dest;
        this.data = [];
    }

    update_altitude(new_alt) {
        this.alt = new_alt;
        this.data.push(['altitude', new_alt]);
    }

    update_speed(new_speed) {
        this.speed = new_speed;
        this.data.push(['speed', new_speed]);
    }

    plan_cruise(target_alt) {
        if (this.alt < target_alt) {
            this.update_altitude(target_alt);
            this.update_speed(this.speed + 10);
        } else {
            this.update_speed(this.speed - 5);
        }
    }
}

class CruisePlanner {
    constructor(trajectory) {
        this.trajectory = trajectory;
    }

    execute_plan(target_alt) {
        while (this.trajectory.alt < target_alt) {
            this.trajectory.plan_cruise(target_alt);
        }
        this.trajectory.plan_cruise(target_alt);
    }
}

function main() {
    const initial_alt = 5000;
    const initial_speed = 300;
    const destination = 'New York';
    const trajectory = new FlightTrajectory(initial_alt, initial_speed, destination);
    const planner = new CruisePlanner(trajectory);
    planner.execute_plan(35000);
}

main();