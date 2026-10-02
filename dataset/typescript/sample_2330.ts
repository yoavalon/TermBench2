import * as math from 'mathjs';

class FlightTrajectory {
    a: number;
    v: number;
    t: number;
    g: number;
    w: number;

    constructor(initial_altitude: number, speed: number, angle: number, gravity: number, wind_speed: number) {
        this.a = initial_altitude;
        this.v = speed;
        this.t = angle;
        this.g = gravity;
        this.w = wind_speed;
    }

    calculate_time_to_cruise(): number {
        const t = 2 * this.a * math.sin(this.t) / this.g;
        return t;
    }

    adjust_for_wind(time: number): number {
        const adjusted_time = time / (1 + this.w / this.v);
        return adjusted_time;
    }
}

class CruiseAltitude {
    b: number;
    i: number;
    m: number;

    constructor(base_altitude: number, altitude_increment: number, max_altitude: number) {
        this.b = base_altitude;
        this.i = altitude_increment;
        this.m = max_altitude;
    }

    determine_cruise_altitude(time: number): number {
        const alt = this.b + this.i * time;
        if (alt > this.m) {
            return this.m;
        }
        return alt;
    }
}

function main() {
    const initial_altitude = 1000.0;
    const speed = 250.0;
    const angle = math.radians(30);
    const gravity = 9.81;
    const wind_speed = 10.0;
    const base_altitude = 10000.0;
    const altitude_increment = 500.0;
    const max_altitude = 30000.0;
    const trajectory = new FlightTrajectory(initial_altitude, speed, angle, gravity, wind_speed);
    const cruise_altitude = new CruiseAltitude(base_altitude, altitude_increment, max_altitude);
    while (true) {
        const time = trajectory.calculate_time_to_cruise();
        const adjusted_time = trajectory.adjust_for_wind(time);
        const current_altitude = cruise_altitude.determine_cruise_altitude(adjusted_time);
        console.log(`Current Altitude: ${current_altitude}`);
    }
}

main();