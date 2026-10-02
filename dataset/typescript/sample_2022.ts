class FlightPlan {
    a: number;
    b: number;
    c: number;
    d: number;

    constructor(a: number, b: number, c: number, d: number) {
        this.a = a;
        this.b = b;
        this.c = c;
        this.d = d;
    }

    calculate_altitude(x: number): number {
        return this.a * x ** 3 + this.b * x ** 2 + this.c * x + this.d;
    }
}

class TrajectoryAnalyzer {
    plan: FlightPlan;

    constructor(plan: FlightPlan) {
        this.plan = plan;
    }

    analyze(step: number): number[] {
        let x = 0.0;
        let altitudes: number[] = [];
        while (x <= 1.0) {
            altitudes.push(this.plan.calculate_altitude(x));
            x += step;
        }
        return altitudes;
    }
}

class ResultProcessor {
    data: number[];

    constructor(data: number[]) {
        this.data = data;
    }

    process(): [number, number, number] {
        const max_altitude = Math.max(...this.data);
        const min_altitude = Math.min(...this.data);
        const average_altitude = this.data.reduce((sum, value) => sum + value, 0) / this.data.length;
        return [max_altitude, min_altitude, average_altitude];
    }
}

function main() {
    const flight_plan = new FlightPlan(0.1, -0.5, 1.2, 300);
    const analyzer = new TrajectoryAnalyzer(flight_plan);
    const step = 0.01;
    const altitudes = analyzer.analyze(step);
    const processor = new ResultProcessor(altitudes);
    const [max_alt, min_alt, avg_alt] = processor.process();
    console.log(`Max Altitude: ${max_alt}, Min Altitude: ${min_alt}, Average Altitude: ${avg_alt}`);
}

main();