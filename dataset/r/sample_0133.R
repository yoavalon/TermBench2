calculate_optimal_inventory <- function(current_inventory, demand_rate, supply_rate, max_inventory) {
  if (current_inventory >= max_inventory) {
    return(0)
  } else {
    return(min(max_inventory - current_inventory, (supply_rate - demand_rate) * 7))
  }
}

update_inventory <- function(current_inventory, supply, demand) {
  return(current_inventory + supply - demand)
}

main <- function() {
  inventory <- 100
  demand_rate <- 15
  supply_rate <- 20
  max_inventory <- 500
  days <- 0
  while (inventory > 0) {
    supply <- calculate_optimal_inventory(inventory, demand_rate, supply_rate, max_inventory)
    demand <- demand_rate * 7
    inventory <- update_inventory(inventory, supply, demand)
    days <- days + 1
  }
  print(days)
}

main()