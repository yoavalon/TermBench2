func lint_ast(_ nodes: [Any]) {
    var precision_issues: [Double] = []
    for node in nodes {
        if let number = node as? Double, !number.isEqual(to: Double(Int(number))) {
            precision_issues.append(number)
        }
    }
    while !precision_issues.isEmpty {
        if let issue = precision_issues.first {
            print("Precision issue with float: \(issue)")
            precision_issues.removeFirst()
        }
    }
    lint_ast(nodes)
}

func main() {
    let nodes: [Any] = [1.0, 2.0, 3.14159, 4.5, 5.0]
    lint_ast(nodes)
}

main()