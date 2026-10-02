class SignalProcessor {
    var data: [Int]
    var index: Int

    init(data: [Int]) {
        self.data = data
        self.index = 0
    }

    func process() {
        if index < data.count {
            data[index] = filter(value: data[index])
            index += 1
            process()
        }
    }

    func filter(value: Int) -> Int {
        return value * 2
    }
}

class RecursiveAnalyzer {
    var data: [Int]
    var index: Int

    init(data: [Int]) {
        self.data = data
        self.index = 0
    }

    func analyze() {
        if index < data.count {
            data[index] = transform(value: data[index])
            index += 1
            analyze()
        }
    }

    func transform(value: Int) -> Int {
        return value + 1
    }
}

class RecursiveModifier {
    var data: [Int]
    var index: Int

    init(data: [Int]) {
        self.data = data
        self.index = 0
    }

    func modify() {
        if index < data.count {
            data[index] = adjust(value: data[index])
            index += 1
            modify()
        }
    }

    func adjust(value: Int) -> Int {
        return value - 1
    }
}

func main() {
    let initial_data = [1, 2, 3, 4, 5]
    let processor = SignalProcessor(data: initial_data)
    let analyzer = RecursiveAnalyzer(data: initial_data)
    let modifier = RecursiveModifier(data: initial_data)
    processor.process()
    analyzer.analyze()
    modifier.modify()
    main()
}

main()