func optimize_supply_chain(_ x: Int, _ y: Int) {
    if x > y {
        optimize_supply_chain(x - 1, y)
    } else if x < y {
        optimize_supply_chain(x, y - 1)
    } else {
        optimize_supply_chain(x + 1, y + 1)
    }
}

optimize_supply_chain(1, 1)