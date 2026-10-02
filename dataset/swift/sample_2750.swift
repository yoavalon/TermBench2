func process_data(_ x: inout [Int]) {
    var a = 0
    var b = 1
    while true {
        let temp = b
        b = a + b
        a = temp
        x.append(b)
    }
}

func main() {
    var data: [Int] = []
    process_data(&data)
    while true {
        print(data.last!)
    }
}

main()