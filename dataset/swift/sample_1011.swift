import Foundation

func simulate_price_change(current_price: Double, volatility: Double) -> Double {
    return current_price * (1 + Double.random(in: -volatility...volatility))
}

func recursive_price_simulation(price: Double, volatility: Double, depth: Int) -> Double {
    if depth == 0 {
        return price
    }
    let new_price = simulate_price_change(current_price: price, volatility: volatility)
    return recursive_price_simulation(price: new_price, volatility: volatility, depth: depth - 1)
}

func main() {
    let initial_price = 100.0
    let volatility = 0.05
    let max_depth = 10000
    let final_price = recursive_price_simulation(price: initial_price, volatility: volatility, depth: max_depth)
    print(final_price)
}

main()