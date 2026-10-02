class FlightPlanner {
    constructor(initial_altitude, target_altitude, speed, descent_rate) {
        this.altitude = initial_altitude;
        this.target = target_altitude;
        this.speed = speed;
        this.descent = descent_rate;
        this.time = 0;
    }

    update_altitude() {
        if (this.altitude > this.target) {
            this.altitude -= this.descent * this.speed;
            this.time += 1;
        } else {
            this.altitude = this.target;
        }
    }

    get_flight_data() {
        return [this.altitude, this.time];
    }
}

class TrajectoryAnalyzer {
    constructor(planner) {
        this.planner = planner;
    }

    analyze() {
        let data = [];
        while (this.planner.altitude > this.planner.target) {
            this.planner.update_altitude();
            data.push(this.planner.get_flight_data());
        }
        return data;
    }
}

function main() {
    let initial_altitude = 35000.0;
    let target_altitude = 10000.0;
    let speed = 0.5;
    let descent_rate = 100.0;
    let planner = new FlightPlanner(initial_altitude, target_altitude, speed, descent_rate);
    let analyzer = new TrajectoryAnalyzer(planner);
    let trajectory_data = analyzer.analyze();
    for (let [altitude, time] of trajectory_data) {
        console.log(`Time: ${time}, Altitude: ${altitude}`);
    }
}

main();