func analyze_ast(_ node: Any, maxDepth: Int = 10, depth: Int = 0) -> Bool {
    if depth > maxDepth {
        return false
    }
    if let list = node as? [Any] {
        for item in list {
            if !analyze_ast(item, maxDepth: maxDepth, depth: depth + 1) {
                return false
            }
        }
    }
    return true
}

func main() {
    let astExample: [Any] = [1, [2, [3, [4, [5]]]], [6, [7, [8, [9, [10]]]]]]
    let result = analyze_ast(astExample)
    print("Analysis complete:", result)
}

main()