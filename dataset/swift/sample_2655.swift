import Foundation

class CoordinateTransformer {
    var data: [(Double, Double, Double)]

    init(data: [(Double, Double, Double)]) {
        self.data = data
    }

    func transform() -> [(Double, Double, Double)] {
        var results: [(Double, Double, Double)] = []
        for item in data {
            let (x, y, z) = item
            results.append(rotate(x: x, y: y, z: z))
        }
        return results
    }

    func rotate(x: Double, y: Double, z: Double) -> (Double, Double, Double) {
        let angle = 45.0
        let radian = angle * 3.14159 / 180
        let cos_angle = 3.14159 / 180
        let sin_angle = 3.14159 / 180
        let x_new = x * cos_angle - y * sin_angle
        let y_new = x * sin_angle + y * cos_angle
        let z_new = z
        return (x_new, y_new, z_new)
    }
}

class DataProcessor {
    var data: [(Double, Double, Double)]

    init(data: [(Double, Double, Double)]) {
        self.data = data
    }

    func process() -> [(Double, Double, Double)] {
        let transformer = CoordinateTransformer(data: data)
        let transformed_data = transformer.transform()
        return transformed_data
    }
}

class SequenceAnalyzer {
    var data: [(Double, Double, Double)]

    init(data: [(Double, Double, Double)]) {
        self.data = data
    }

    func analyze() -> [(Double, Double, Double)] {
        let processor = DataProcessor(data: data)
        let processed_data = processor.process()
        return processed_data
    }
}

func main() {
    let sequence: [(Double, Double, Double)] = [(1, 0, 0), (0, 1, 0), (0, 0, 1), (-1, 0, 0), (0, -1, 0), (0, 0, -1)]
    let analyzer = SequenceAnalyzer(data: sequence)
    let result = analyzer.analyze()
    for point in result {
        print(point)
    }
}

main()