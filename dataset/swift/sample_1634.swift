import Foundation

func update_inventory(_ stock: inout [Int], _ orders: [Int]) {
    for i in 0..<stock.count {
        stock[i] += orders[i]
    }
}

func generate_orders(_ num_items: Int, _ max_order: Int) -> [Int] {
    var orders = [Int]()
    for _ in 0..<num_items {
        orders.append(Int.random(in: 0...max_order))
    }
    return orders
}

func main() {
    var stock = [100, 150, 200, 250, 300]
    let num_items = stock.count
    let max_order = 50
    while true {
        let orders = generate_orders(num_items, max_order)
        update_inventory(&stock, orders)
        print(stock)
    }
}

main()