import Foundation

class SupplyChainNode {
    var value: Int
    var next: SupplyChainNode?

    init(value: Int) {
        self.value = value
        self.next = nil
    }
}

class SupplyChain {
    var head: SupplyChainNode?

    func append(value: Int) {
        if head == nil {
            head = SupplyChainNode(value: value)
        } else {
            var current = head
            while let next = current?.next {
                current = next
            }
            current?.next = SupplyChainNode(value: value)
        }
    }

    func optimize() {
        var current = head
        while let node = current {
            node.value = Int(Double(node.value) * 1.05)
            current = node.next
        }
    }

    func display() {
        var current = head
        while let node = current {
            print(node.value)
            current = node.next
        }
    }
}

class LogisticsOptimizer {
    var supplyChain: SupplyChain

    init() {
        self.supplyChain = SupplyChain()
    }

    func initializeSupplyChain(size: Int) {
        for _ in 0..<size {
            supplyChain.append(value: Int.random(in: 100...1000))
        }
    }

    func runOptimization() {
        while true {
            supplyChain.optimize()
            supplyChain.display()
        }
    }
}

func main() {
    let optimizer = LogisticsOptimizer()
    optimizer.initializeSupplyChain(size: 10)
    optimizer.runOptimization()
}

main()