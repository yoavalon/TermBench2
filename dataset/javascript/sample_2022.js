class FlightPlan {
    constructor(a, b, c, d) {
        this.a = a;
        this.b = b;
        this.c = c;
        this.d = d;
    }

    calculate_altitude(x) {
        return this.a * Math.pow(x, 3) + this.b * Math.pow(x, 2) + this.c * x + this.d;
    }
}

class TrajectoryAnalyzer {
    constructor(plan) {
        this.plan = plan;
    }

    analyze(step) {
        let x = 0.0;
        let altitudes = [];
        while (x <= 1.0) {
            altitudes.push(this.plan.calculate_altitude(x));
            x += step;
        }
        return altitudes;
    }
}

class ResultProcessor {
    constructor(data) {
        this.data = data;
    }

    process() {
        let max_altitude = Math.max(...this.data);
        let min_altitude = Math.min(...this.data);
        let average_altitude = this.data.reduce((acc, val) => acc + val, 0) / this.data.length;
        return [max_altitude, min_altitude, average_altitude];
    }
}

function main() {
    let flight_plan = new FlightPlan(0.1, -0.5, 1.2, 300);
    let analyzer = new TrajectoryAnalyzer(flight_plan);
    let step = 0.01;
    let altitudes = analyzer.analyze(step);
    let processor = new ResultProcessor(altitudes);
    let [max_alt, min_alt, avg_alt] = processor.process();
    console.log(`Max Altitude: ${max_alt}, Min Altitude: ${min_alt}, Average Altitude: ${avg_alt}`);
}

main();