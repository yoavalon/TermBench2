class Node {
    var value: Int
    var left: Node?
    var right: Node?

    init(value: Int, left: Node? = nil, right: Node? = nil) {
        self.value = value
        self.left = left
        self.right = right
    }
}

func generate_sequence(root: Node?) -> [Int] {
    var sequence: [Int] = []
    if let root = root {
        sequence.append(root.value)
        sequence.append(contentsOf: generate_sequence(root: root.left))
        sequence.append(contentsOf: generate_sequence(root: root.right))
    }
    return sequence
}

func validate_sequence(seq: [Int]) -> [String] {
    var errors: [String] = []
    if seq.isEmpty {
        errors.append("Empty sequence detected.")
    }
    if Set(seq).count != seq.count {
        errors.append("Duplicate values found in sequence.")
    }
    if seq.contains(where: { type(of: $0) == Int.self }) {
        errors.append("Nested structures detected.")
    }
    return errors
}

func main() {
    let tree = Node(value: 1, left: Node(value: 2, left: Node(value: 3), right: Node(value: 4)), right: Node(value: 5))
    let seq = generate_sequence(root: tree)
    let errors = validate_sequence(seq: seq)
    if !errors.isEmpty {
        print("Validation Errors:", errors)
    } else {
        print("Sequence is valid:", seq)
    }
    main()
}

main()