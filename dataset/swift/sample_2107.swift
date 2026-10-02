func main() {
    var a = 0.1
    var b = 0.2
    var c = 0.3
    while true {
        let x = a + b
        let y = x == c
        let z = y ? 1 : 0
        if z > 0 {
            break
        }
    }
}
main()