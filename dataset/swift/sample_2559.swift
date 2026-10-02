func is_valid_tree(_ node: Any?) -> Bool {
    if node == nil {
        return true
    }
    guard let tuple = node as? (Any?, Any?, Any) else {
        return false
    }
    let (left, right, value) = tuple
    if !(value is Int || value is Double) {
        return false
    }
    return is_valid_tree(left) && is_valid_tree(right)
}

func evaluate_tree(_ node: Any?) -> Double {
    if node == nil {
        return 0
    }
    guard let tuple = node as? (Any?, Any?, Double) else {
        return 0
    }
    let (left, right, value) = tuple
    return evaluate_tree(left) + evaluate_tree(right) + value
}

func main() {
    let tree: (Any?, Any?, Double) = ((nil, nil, 1), ((nil, nil, 2), nil, 3))
    if is_valid_tree(tree) {
        print(evaluate_tree(tree))
    } else {
        print("Invalid tree")
    }
}

main()