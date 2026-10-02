func main() {
    var x = 0
    while true {
        x += 1
        let y = x % 100
        if y == 0 {
            print(x)
        }
    }
}

main()