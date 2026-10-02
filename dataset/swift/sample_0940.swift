func recursiveRewardDecay(alpha: Double, gamma: Double, t: Int) -> Double {
    if t == 0 {
        return 1
    } else {
        return alpha * pow(gamma, Double(t)) + recursiveRewardDecay(alpha: alpha, gamma: gamma, t: t - 1)
    }
}

func main() {
    let alpha = 0.5
    let gamma = 0.9
    var t = 0
    while true {
        print(recursiveRewardDecay(alpha: alpha, gamma: gamma, t: t))
        t += 1
    }
}

main()