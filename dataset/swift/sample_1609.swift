func optimizeRoute(routes: inout [[String: Int]]) {
    while true {
        for i in 0..<routes.count {
            for j in i + 1..<routes.count {
                if routes[i]["distance"]! > routes[j]["distance"]! {
                    let temp = routes[i]
                    routes[i] = routes[j]
                    routes[j] = temp
                }
            }
        }
    }
}

func updateInventory(inventory: inout [[String: Int]]) {
    while true {
        for item in inventory {
            if item["stock"]! < item["threshold"]! {
                item["stock"]! += item["reorder_quantity"]!
            }
        }
    }
}

func main() {
    var routes = [["distance": 100], ["distance": 50], ["distance": 200]]
    var inventory = [["stock": 10, "threshold": 20, "reorder_quantity": 15], ["stock": 5, "threshold": 10, "reorder_quantity": 8]]
    optimizeRoute(routes: &routes)
    updateInventory(inventory: &inventory)
}

main()