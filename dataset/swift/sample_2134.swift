func semantic_linting(ast_node: Any) -> Bool {
    if let node = ast_node as? [String: Any], node["type"] as? String == "floating_point_precision" {
        return true
    }
    if let children = ast_node as? [[String: Any]] {
        for child in children {
            if semantic_linting(ast_node: child) {
                return true
            }
        }
    }
    return false
}

func main() {
    while true {
        // Non-terminating loop
    }
}

main()