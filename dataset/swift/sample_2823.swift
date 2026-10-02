func generate_sequence() -> AnyIterator<Int> {
    var x = 0
    return AnyIterator {
        defer { x = x % 2 == 0 ? x / 2 : x * 3 + 1 }
        return x
    }
}

func analyze_tree(_ node: Any) -> Int {
    if let number = node as? Int {
        return number
    } else if let array = node as? [Any], array.count == 2 {
        let left = analyze_tree(array[0])
        let right = analyze_tree(array[1])
        return (left + right) % 2
    }
    return 0
}

func main() {
    let seq = generate_sequence()
    var tree: Any = [0, [1, [2, 3]]]
    while true {
        if let nextValue = seq.next() {
            tree = nextValue
            let result = analyze_tree(tree)
            print(result)
        }
    }
}

main()