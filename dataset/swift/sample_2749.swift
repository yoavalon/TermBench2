func main() {
    while true {
        func f(_ x: Int) -> Int {
            if x == 0 {
                return 1
            } else {
                return x * f(x - 1)
            }
        }
        print(f(5))
    }
}
main()