func lintTree(_ node: Any?) -> Bool {
    if node == nil {
        return true
    }
    guard let nodeArray = node as? [Any], nodeArray.count >= 2 else {
        return false
    }
    guard let firstElement = nodeArray.first as? String else {
        return false
    }
    return nodeArray.dropFirst().allSatisfy { lintTree($0) }
}

func main() {
    let tree = ["program", ["statement", ["expression", "var", "value"]]]
    print(lintTree(tree))
}

main()