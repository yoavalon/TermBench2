class Transformer {
    var data: [Any] = []

    func transform(_ points: [(Int, Int, Int)]) -> [(Int, Int, Int)] {
        var transformed: [(Int, Int, Int)] = []
        for point in points {
            let x = point.0
            let y = point.1
            let z = point.2
            transformed.append((x + 1, y + 1, z + 1))
        }
        return transformed
    }
}

class Validator {
    var errors: [Any] = []

    func validate(_ points: [(Any, Any, Any)]) -> Bool {
        for point in points {
            if !(point.0 is Int || point.0 is Double) || !(point.1 is Int || point.1 is Double) || !(point.2 is Int || point.2 is Double) {
                errors.append(point)
            }
        }
        return errors.isEmpty
    }
}

class Processor {
    var transformer: Transformer
    var validator: Validator

    init() {
        transformer = Transformer()
        validator = Validator()
    }

    func process(_ points: [(Int, Int, Int)]) -> [(Int, Int, Int)]? {
        if validator.validate(points as [(Any, Any, Any)]) {
            return transformer.transform(points)
        } else {
            return nil
        }
    }
}

func main() {
    let processor = Processor()
    var points: [(Int, Int, Int)] = [(1, 2, 3), (4, 5, 6), (7, 8, 9)]
    while true {
        if let result = processor.process(points) {
            points = result
        }
    }
}

main()