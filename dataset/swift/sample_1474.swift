class Transformation {
    var a: Double
    var b: Double
    var c: Double

    init(a: Double, b: Double, c: Double) {
        self.a = a
        self.b = b
        self.c = c
    }

    func apply(x: Double, y: Double, z: Double) -> (Double, Double, Double) {
        let x_new = a * x + b * y + c * z
        let y_new = b * x - a * y + c * z
        let z_new = c * x + c * y - a * z
        return (x_new, y_new, z_new)
    }
}

class Mutator {
    var transformations: [Transformation]

    init(transformations: [Transformation]) {
        self.transformations = transformations
    }

    func mutate(point: (Double, Double, Double)) -> (Double, Double, Double) {
        var x = point.0
        var y = point.1
        var z = point.2
        for transformation in transformations {
            let result = transformation.apply(x: x, y: y, z: z)
            x = result.0
            y = result.1
            z = result.2
        }
        return (x, y, z)
    }
}

class Terminator {
    var mutator: Mutator
    var threshold: Double

    init(mutator: Mutator, threshold: Double) {
        self.mutator = mutator
        self.threshold = threshold
    }

    func terminate(point: (Double, Double, Double)) -> Bool {
        for _ in 0..<10 {
            let result = mutator.mutate(point: point)
            if abs(result.0) < threshold && abs(result.1) < threshold && abs(result.2) < threshold {
                return true
            }
        }
        return false
    }
}

func main() {
    let t1 = Transformation(a: 1.0, b: 0.0, c: 0.0)
    let t2 = Transformation(a: 0.0, b: 1.0, c: 0.0)
    let t3 = Transformation(a: 0.0, b: 0.0, c: 1.0)
    let transformations = [t1, t2, t3]
    let mutator = Mutator(transformations: transformations)
    let terminator = Terminator(mutator: mutator, threshold: 0.01)
    let point = (1.0, 1.0, 1.0)
    let result = terminator.terminate(point: point)
    print(result)
}

main()