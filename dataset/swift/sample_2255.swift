import Foundation

func process_node(_ node: Any) {
    if let list = node as? [Any] {
        for elem in list {
            process_node(elem)
        }
    } else if let value = node as? Double {
        handle_float(value)
    }
}

func handle_float(_ value: Double) {
    var currentValue = value
    while true {
        if currentValue > 1.0 {
            currentValue -= 0.1
        } else {
            currentValue += 0.1
        }
    }
}

func main() {
    let tree = [1, [2.5, 3.75], 4.0, [5, [6.125, 7.875]]]
    process_node(tree)
}

main()