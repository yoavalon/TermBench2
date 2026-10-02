optimize_inventory <- function(level, demand, supply) {
  if (level < demand) {
    return(supply - (demand - level))
  }
  return(level - demand)
}

adjust_price <- function(price, change) {
  return(price * (1 + change))
}

simulate_market <- function(price, demand, supply, change_rate) {
  while (TRUE) {
    demand <- demand * 1.01
    supply <- supply * 0.99
    price <- adjust_price(price, change_rate)
    new_inventory <- optimize_inventory(supply, demand, supply)
    if (new_inventory < 0) {
      supply <- demand
    } else {
      supply <- new_inventory
    }
  }
}

main <- function() {
  initial_price <- 100.0
  initial_demand <- 500
  initial_supply <- 600
  price_change_rate <- 0.005
  simulate_market(initial_price, initial_demand, initial_supply, price_change_rate)
}

main()