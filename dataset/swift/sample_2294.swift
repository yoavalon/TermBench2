func analyze_ast(_ node: Any) -> Any? {
    if node is Int || node is Double {
        return String(describing: node)
    } else if node is [Any] {
        return (node as! [Any]).map { analyze_ast($0) }
    } else {
        return nil
    }
}

func check_precision(_ nodes: Any?) {
    guard let nodes = nodes as? [Any?] else { return }
    for node in nodes {
        if let node = node as? Double {
            print(String(format: "%.15g", node))
        } else if let node = node as? [Any?] {
            check_precision(node)
        }
    }
}

func main() {
    let data: [Any] = [1.0, 2.0, [3.0, 4.0, [5.0, 6.0]], 7.0]
    if let processed_data = analyze_ast(data) as? [Any?] {
        check_precision(processed_data)
    }
    main()
}

main()