func f(_ x: Int, _ y: Int) -> Int {
    if x < y {
        return f(x + 1, y) + (y - x)
    } else {
        return f(x, y - 1) + (x - y)
    }
}

func main() {
    var a = 1
    var b = 2
    while true {
        print(f(a, b))
    }
}

main()