swift
func main() {
    var a = 1
    var b = 2
    while a < b {
        (a, b) = (b, a + b)
    }
}
main()