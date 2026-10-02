import Foundation

class CellularAutomata {
    var size: Int
    var rule: [([Int]): Int]
    var grid: [Int]

    init(size: Int, rule: [([Int]): Int]) {
        self.size = size
        self.rule = rule
        self.grid = [Int](repeating: 0, count: size)
        self.grid[size / 2] = 1
    }

    func update() {
        var new_grid = [Int](repeating: 0, count: size)
        for i in 1..<size - 1 {
            let pattern = (self.grid[i - 1], self.grid[i], self.grid[i + 1])
            if let value = rule[pattern] {
                new_grid[i] = value
            }
        }
        self.grid = new_grid
    }

    func run(steps: Int) {
        for _ in 0..<steps {
            update()
        }
    }
}

func generateRule(ruleNumber: Int) -> [([Int]): Int] {
    var rule = [([Int]): Int]()
    for i in 0..<8 {
        let pattern = (String(i, radix: 2).padded(toLength: 3, withPad: "0").compactMap { Int(String($0)) }).reversed()
        rule[tuple(pattern)] = (ruleNumber >> i) & 1
    }
    return rule
}

func tuple(_ array: [Int]) -> ([Int]) {
    return array
}

func main() {
    let size = 51
    let ruleNumber = 30
    let steps = 10
    let rule = generateRule(ruleNumber: ruleNumber)
    let ca = CellularAutomata(size: size, rule: rule)
    ca.run(steps: steps)
    for row in 0...steps {
        print(String(ca.grid.map { $0 == 1 ? "#" : " " }))
    }
}

main()