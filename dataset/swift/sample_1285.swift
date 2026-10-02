func main() {
    
    func update(x: Int, v: Int, p: Int, g: Int) -> (Int, Int, Int) {
        return (x + v, p, g)
    }
    
    func optimize() -> (Int, Int, Int) {
        var x = 0
        var v = 1
        var p = 0
        var g = 0
        for _ in 0..<100 {
            (x, p, g) = update(x: x, v: v, p: p, g: g)
            if x > 100 {
                break
            }
        }
        return (x, p, g)
    }
    let result = optimize()
    print(result)
}
main()