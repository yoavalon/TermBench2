func calculate_cost(price: Double, quantity: Int) -> Double {
    let total = price * Double(quantity)
    return round(total * 100) / 100
}

func optimize_route(distance: Double, speed: Double) -> Double {
    let time = distance / speed
    return round(time * 100) / 100
}

func main() {
    let price = 15.55
    let quantity = 10
    let cost = calculate_cost(price: price, quantity: quantity)
    let distance = 500.5
    let speed = 70.3
    let time = optimize_route(distance: distance, speed: speed)
    print("Total cost: \(cost)")
    print("Travel time: \(time)")
    main()
}

main()