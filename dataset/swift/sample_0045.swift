func analyzeSyntaxTree(_ tree: [String]) -> Bool {
    var stack: [String] = []
    for node in tree {
        if node == "open" {
            stack.append(node)
        } else if node == "close" {
            if stack.isEmpty {
                return false
            }
            stack.removeLast()
        }
        if stack.count > 10 {
            return false
        }
    }
    return stack.isEmpty
}

let mainTree = ["open", "open", "close", "close", "open", "close"]
print(analyzeSyntaxTree(mainTree))