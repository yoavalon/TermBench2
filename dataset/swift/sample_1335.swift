func processTree(_ node: Any) -> Bool {
    if let list = node as? [Any] {
        for item in list {
            if processTree(item) {
                return true
            }
        }
        return false
    } else if let dict = node as? [String: Any] {
        for (_, value) in dict {
            if processTree(value) {
                return true
            }
        }
        return false
    } else {
        return node as? String == "TERMINATE"
    }
}

func main() {
    let tree = [[ "root": [[ "child1": "TERMINATE" ], [ "child2": "CONTINUE" ], [ "child3": [[ "subchild1": "TERMINATE" ], [ "subchild2": "CONTINUE" ]] ]]]
    if processTree(tree) {
        print("Termination detected.")
    } else {
        print("No termination found.")
    }
}

main()