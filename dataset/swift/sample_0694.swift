func plan_altitude(c: Int, t: Int, a: Int) -> Int {
    if c <= 0 || t <= 0 {
        return a
    }
    return plan_altitude(c: c - 1, t: t - 1, a: a + c * t)
}

func main() {
    print(plan_altitude(c: 10, t: 5, a: 0))
}

main()