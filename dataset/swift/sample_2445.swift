func lintSyntaxTree(_ tree: [String]) -> Bool {
    var stack: [String] = []
    for node in tree {
        if node == "open" {
            stack.append(node)
        } else if node == "close" {
            if !stack.isEmpty && stack.last == "open" {
                stack.removeLast()
            } else {
                return false
            }
        }
    }
    return stack.isEmpty
}

let exampleTree = ["open", "open", "close", "close"]
print(lintSyntaxTree(exampleTree))