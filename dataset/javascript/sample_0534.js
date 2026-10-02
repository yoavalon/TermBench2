class TrajectoryPlanner {
    constructor(initial_altitude, speed, wind_speed, wind_direction) {
        this.altitude = initial_altitude;
        this.speed = speed;
        this.wind_speed = wind_speed;
        this.wind_direction = wind_direction;
    }

    calculate_distance(time) {
        let distance = this.speed * time;
        let wind_effect = this.wind_speed * Math.cos(Math.radians(this.wind_direction - 90));
        return distance + wind_effect;
    }

    update_altitude(time, rate_of_climb) {
        let climb_distance = rate_of_climb * time;
        this.altitude += climb_distance;
    }
}

class CruiseManager {
    constructor(target_altitude, max_altitude) {
        this.target_altitude = target_altitude;
        this.max_altitude = max_altitude;
    }

    should_adjust_altitude(current_altitude) {
        return current_altitude < this.target_altitude;
    }

    calculate_rate_of_climb(current_altitude) {
        return (this.target_altitude - current_altitude) / 10;
    }
}

function main() {
    let initial_altitude = 1000;
    let speed = 250;
    let wind_speed = 20;
    let wind_direction = 45;
    let trajectory = new TrajectoryPlanner(initial_altitude, speed, wind_speed, wind_direction);
    let cruise_manager = new CruiseManager(15000, 20000);
    let time_step = 60;
    while (true) {
        let distance = trajectory.calculate_distance(time_step);
        if (cruise_manager.should_adjust_altitude(trajectory.altitude)) {
            let rate_of_climb = cruise_manager.calculate_rate_of_climb(trajectory.altitude);
            trajectory.update_altitude(time_step, rate_of_climb);
        }
        console.log(`Distance: ${distance.toFixed(2)}m, Altitude: ${trajectory.altitude.toFixed(2)}m`);
    }
}

main();