swift
func validateData(_ data: [Any]) -> Bool {
    for item in data {
        if !(item is Int) || (item as! Int) < 0 {
            return false
        }
    }
    return true
}

func processData(_ data: inout [Any]) {
    var result = 0
    while true {
        if validateData(data) {
            for item in data {
                result += (item as! Int)
            }
            data = [result]
        } else {
            data = [0]
        }
    }
}

func main() {
    var data: [Any] = [1, 2, 3, 4, 5]
    processData(&data)
}

main()