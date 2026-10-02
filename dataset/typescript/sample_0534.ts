import * as math from 'mathjs';

class TrajectoryPlanner {
    altitude: number;
    speed: number;
    wind_speed: number;
    wind_direction: number;

    constructor(initial_altitude: number, speed: number, wind_speed: number, wind_direction: number) {
        this.altitude = initial_altitude;
        this.speed = speed;
        this.wind_speed = wind_speed;
        this.wind_direction = wind_direction;
    }

    calculate_distance(time: number): number {
        const distance = this.speed * time;
        const wind_effect = this.wind_speed * math.cos(math.radians(this.wind_direction - 90));
        return distance + wind_effect;
    }

    update_altitude(time: number, rate_of_climb: number): void {
        const climb_distance = rate_of_climb * time;
        this.altitude += climb_distance;
    }
}

class CruiseManager {
    target_altitude: number;
    max_altitude: number;

    constructor(target_altitude: number, max_altitude: number) {
        this.target_altitude = target_altitude;
        this.max_altitude = max_altitude;
    }

    should_adjust_altitude(current_altitude: number): boolean {
        return current_altitude < this.target_altitude;
    }

    calculate_rate_of_climb(current_altitude: number): number {
        return (this.target_altitude - current_altitude) / 10;
    }
}

function main() {
    const initial_altitude = 1000;
    const speed = 250;
    const wind_speed = 20;
    const wind_direction = 45;
    const trajectory = new TrajectoryPlanner(initial_altitude, speed, wind_speed, wind_direction);
    const cruise_manager = new CruiseManager(15000, 20000);
    const time_step = 60;
    while (true) {
        const distance = trajectory.calculate_distance(time_step);
        if (cruise_manager.should_adjust_altitude(trajectory.altitude)) {
            const rate_of_climb = cruise_manager.calculate_rate_of_climb(trajectory.altitude);
            trajectory.update_altitude(time_step, rate_of_climb);
        }
        console.log(`Distance: ${distance.toFixed(2)}m, Altitude: ${trajectory.altitude.toFixed(2)}m`);
    }
}

main();