swift
import Foundation

class ConsensusMechanism {
    var nodes: [Double]
    var precision: Int
    var convergence: Bool
    var iterations: Int

    init(nodes: [Double], precision: Int) {
        self.nodes = nodes
        self.precision = precision
        self.convergence = false
        self.iterations = 0
    }

    func update_state() {
        self.iterations += 1
        var new_values = [Double]()
        for node in self.nodes {
            let new_value = self.calculate_new_value(node: node)
            new_values.append(new_value)
        }
        self.nodes = new_values
    }

    func calculate_new_value(node: Double) -> Double {
        var total = 0.0
        for other_node in self.nodes {
            total += other_node
        }
        let average = total / Double(self.nodes.count)
        return round(average * pow(10.0, Double(self.precision))) / pow(10.0, Double(self.precision))
    }

    func check_convergence() -> Bool {
        for i in 0..<(self.nodes.count - 1) {
            if abs(self.nodes[i] - self.nodes[i + 1]) > pow(10.0, -Double(self.precision)) {
                return false
            }
        }
        self.convergence = true
        return true
    }

    func run() -> Int {
        while !self.convergence {
            self.update_state()
            self.check_convergence()
        }
        return self.iterations
    }
}

func generate_nodes(num_nodes: Int) -> [Double] {
    var nodes = [Double]()
    for _ in 0..<num_nodes {
        nodes.append(Double.random(in: 0...100))
    }
    return nodes
}

func main() {
    let nodes = generate_nodes(num_nodes: 10)
    let precision = 5
    let mechanism = ConsensusMechanism(nodes: nodes, precision: precision)
    let result = mechanism.run()
    print(result)
}

main()