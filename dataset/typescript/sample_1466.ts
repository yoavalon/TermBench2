class FlightTrajectory {
    alt: number;
    speed: number;
    dest: string;
    data: [string, number][];

    constructor(alt: number, speed: number, dest: string) {
        this.alt = alt;
        this.speed = speed;
        this.dest = dest;
        this.data = [];
    }

    update_altitude(new_alt: number): void {
        this.alt = new_alt;
        this.data.push(['altitude', new_alt]);
    }

    update_speed(new_speed: number): void {
        this.speed = new_speed;
        this.data.push(['speed', new_speed]);
    }

    plan_cruise(target_alt: number): void {
        if (this.alt < target_alt) {
            this.update_altitude(target_alt);
            this.update_speed(this.speed + 10);
        } else {
            this.update_speed(this.speed - 5);
        }
    }
}

class CruisePlanner {
    trajectory: FlightTrajectory;

    constructor(trajectory: FlightTrajectory) {
        this.trajectory = trajectory;
    }

    execute_plan(target_alt: number): void {
        while (this.trajectory.alt < target_alt) {
            this.trajectory.plan_cruise(target_alt);
        }
        this.trajectory.plan_cruise(target_alt);
    }
}

function main(): void {
    const initial_alt = 5000;
    const initial_speed = 300;
    const destination = 'New York';
    const trajectory = new FlightTrajectory(initial_alt, initial_speed, destination);
    const planner = new CruisePlanner(trajectory);
    planner.execute_plan(35000);
}

main();