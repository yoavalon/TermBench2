SupplyChainModel <- function(capacity, demand, cost) {
  inventory <- 0
  revenue <- 0
  total_cost <- 0
  
  update_inventory <- function() {
    if (demand > capacity) {
      inventory <<- inventory + capacity
    } else {
      inventory <<- inventory + demand
    }
  }
  
  calculate_revenue <- function() {
    revenue <<- min(demand, inventory) * cost
  }
  
  calculate_total_cost <- function() {
    total_cost <<- capacity * cost
  }
  
  optimize <- function() {
    update_inventory()
    calculate_revenue()
    calculate_total_cost()
    return(revenue - total_cost)
  }
  
  return(list(
    update_inventory = update_inventory,
    calculate_revenue = calculate_revenue,
    calculate_total_cost = calculate_total_cost,
    optimize = optimize
  ))
}

run_optimization <- function() {
  capacity <- 100
  demand <- 80
  cost <- 10
  model <- SupplyChainModel(capacity, demand, cost)
  profit <- model$optimize()
  return(profit)
}

main <- function() {
  profit <- run_optimization()
  cat('Optimized Profit:', profit, '\n')
}

main()