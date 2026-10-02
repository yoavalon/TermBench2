func plan_altitude(target: Int, current: Int, step: Int) -> Int {
    if abs(target - current) <= step {
        return current
    }
    if target > current {
        return plan_altitude(target: target, current: current + step, step: step)
    } else {
        return plan_altitude(target: target, current: current - step, step: step)
    }
}

func main() {
    print(plan_altitude(target: 35000, current: 10000, step: 5000))
}

main()