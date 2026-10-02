class SignalProcessor {
    var data: [Double]

    init(data: [Double]) {
        self.data = data
    }

    func filter(threshold: Double) -> [Double] {
        func _filter(index: Int) -> [Double] {
            if index >= data.count {
                return []
            }
            if abs(data[index]) > threshold {
                return [data[index]] + _filter(index: index + 1)
            } else {
                return _filter(index: index + 1)
            }
        }
        return _filter(index: 0)
    }
}

class DataTransformer {
    var data: [Double]

    init(data: [Double]) {
        self.data = data
    }

    func transform() -> [Double] {
        func _transform(index: Int) -> [Double] {
            if index >= data.count {
                return []
            }
            return [data[index] * 2] + _transform(index: index + 1)
        }
        return _transform(index: 0)
    }
}

func analyze_signal(data: [Double], threshold: Double) -> [Double] {
    let processor = SignalProcessor(data: data)
    let filtered_data = processor.filter(threshold: threshold)
    let transformer = DataTransformer(data: filtered_data)
    let transformed_data = transformer.transform()
    return transformed_data
}

if let _ = ProcessInfo.processInfo.environment["SWIFT_EXECUTABLE"] {
    let data = [0.1, -0.5, 0.8, -1.2, 0.3, -0.9, 1.1, -0.4]
    let threshold = 0.5
    let result = analyze_signal(data: data, threshold: threshold)
    print(result)
}