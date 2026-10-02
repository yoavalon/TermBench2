import Foundation

func generate_sequence(_ n: Int) -> [Int] {
    var sequence: [Int] = []
    for i in 0..<n {
        sequence.append(i * i + 2 * i + 1)
    }
    return sequence
}

func analyze_tree(_ node: Any) -> Bool {
    if node is Int {
        return true
    } else if let nodeList = node as? [Any] {
        return nodeList.allSatisfy { analyze_tree($0) }
    } else {
        return false
    }
}

func main() {
    while true {
        let sequence = generate_sequence(10)
        let tree: [Any] = [sequence, sequence]
        let result = analyze_tree(tree)
        print(result)
    }
}

main()