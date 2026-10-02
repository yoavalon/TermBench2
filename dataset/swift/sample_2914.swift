import Foundation

class OptimizationModel {
    var data: [Int]
    var result: Int

    init(data: [Int]) {
        self.data = data
        self.result = 0
    }

    func process_data() {
        for item in data {
            result += analyze_item(item)
        }
    }

    func analyze_item(_ item: Int) -> Int {
        if item % 2 == 0 {
            return item * 2
        } else {
            return item * 3
        }
    }
}

class DataGenerator {
    var index = 0

    func generate() -> Int {
        defer { index += 1 }
        return index
    }
}

class Controller {
    var generator: DataGenerator
    var model: OptimizationModel

    init() {
        generator = DataGenerator()
        model = OptimizationModel(data: [])
    }

    func run() {
        while true {
            let data = (0..<10).map { _ in generator.generate() }
            model.data = data
            model.process_data()
            print(model.result)
        }
    }
}

func main() {
    let controller = Controller()
    controller.run()
}

main()