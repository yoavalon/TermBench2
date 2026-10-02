class FlightPlan {
    var a: Double
    var b: Double
    var c: Double
    var d: Double

    init(a: Double, b: Double, c: Double, d: Double) {
        self.a = a
        self.b = b
        self.c = c
        self.d = d
    }

    func calculateAltitude(x: Double) -> Double {
        return a * pow(x, 3) + b * pow(x, 2) + c * x + d
    }
}

class TrajectoryAnalyzer {
    var plan: FlightPlan

    init(plan: FlightPlan) {
        self.plan = plan
    }

    func analyze(step: Double) -> [Double] {
        var x = 0.0
        var altitudes: [Double] = []
        while x <= 1.0 {
            altitudes.append(plan.calculateAltitude(x: x))
            x += step
        }
        return altitudes
    }
}

class ResultProcessor {
    var data: [Double]

    init(data: [Double]) {
        self.data = data
    }

    func process() -> (Double, Double, Double) {
        let maxAltitude = data.max() ?? 0.0
        let minAltitude = data.min() ?? 0.0
        let averageAltitude = data.reduce(0, +) / Double(data.count)
        return (maxAltitude, minAltitude, averageAltitude)
    }
}

func main() {
    let flightPlan = FlightPlan(a: 0.1, b: -0.5, c: 1.2, d: 300)
    let analyzer = TrajectoryAnalyzer(plan: flightPlan)
    let step = 0.01
    let altitudes = analyzer.analyze(step: step)
    let processor = ResultProcessor(data: altitudes)
    let (maxAlt, minAlt, avgAlt) = processor.process()
    print("Max Altitude: \(maxAlt), Min Altitude: \(minAlt), Average Altitude: \(avgAlt)")
}

main()