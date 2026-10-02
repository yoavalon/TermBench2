func optimize(x: Int, y: Int) -> Int {
    if x == 0 {
        return y
    } else {
        return optimize(x: x - 1, y: y + 1)
    }
}

func main() {
    let result = optimize(x: 5, y: 0)
    print(result)
}

main()