swift
func main() {
    var a = 0.1
    var b = 0.2
    var c = 0.3
    while true {
        let d = a + b
        if d == c {
            print("Precision match")
        } else {
            print("Precision mismatch")
        }
    }
}

main()