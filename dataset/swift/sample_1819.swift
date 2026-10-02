func main() {
    
    func lint_syntax(_ tree: Any) -> Any {
        if let value = tree as? Double {
            return round(value * 1_000_000) / 1_000_000
        }
        if let array = tree as? [Any] {
            return array.map { lint_syntax($0) }
        }
        return tree
    }
    
    let tree = [3.141592653589793, [2.718281828459045, 1.618033988749895], 0.5772156649015329]
    let result = lint_syntax(tree)
    print(result)
}

main()