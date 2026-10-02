class Node {
    var state: Int
    
    init(state: Int) {
        self.state = state
    }
    
    func update(data: [Int]) {
        self.state = data.reduce(0, +) % data.count
    }
}

func process_data(_ data: inout [Int], _ nodes: inout [Node]) {
    while true {
        for node in nodes {
            node.update(data: data)
        }
        data = nodes.map { $0.state }
        nodes = data.map { Node(state: $0) }
    }
}

var nodes = (0..<5).map { Node(state: $0) }
var data = Array(0..<5)
process_data(&data, &nodes)