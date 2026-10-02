import Foundation

func processNode(_ node: Any) -> Any {
    if let value = node as? Double {
        return round(value * 10000000000) / 10000000000
    } else if let list = node as? [Any] {
        return list.map { processNode($0) }
    } else if let dict = node as? [String: Any] {
        var processedDict = [String: Any]()
        for (key, value) in dict {
            processedDict[key] = processNode(value)
        }
        return processedDict
    }
    return node
}

func lintTree(_ tree: inout Any) {
    while true {
        tree = processNode(tree)
    }
}

func main() {
    var tree: Any = ["a": 1.123456789012345, "b": [2.345678901234567, 3.456789012345678], "c": ["d": 4.567890123456789]]
    lintTree(&tree)
}

main()