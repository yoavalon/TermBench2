SupplyChain <- setRefClass("SupplyChain",
  fields = list(
    inventory = "numeric",
    demand = "numeric",
    cost = "numeric"
  ),
  methods = list(
    update_inventory = function(supply) {
      inventory <<- inventory + supply
    },
    meet_demand = function() {
      if (demand > inventory) {
        shortage <- demand - inventory
        inventory <<- 0
        return(list(shortage = shortage, fulfilled = 0))
      } else {
        fulfilled <- demand
        inventory <<- inventory - demand
        return(list(shortage = 0, fulfilled = fulfilled))
      }
    },
    calculate_cost = function() {
      return(demand * cost)
    }
  )
)

Optimizer <- setRefClass("Optimizer",
  fields = list(
    supply_chain = "SupplyChain",
    supply = "numeric"
  ),
  methods = list(
    optimize = function() {
      supply_chain$update_inventory(supply)
      result <- supply_chain$meet_demand()
      cost <- supply_chain$calculate_cost()
      return(list(shortage = result$shortage, fulfilled = result$fulfilled, cost = cost))
    }
  )
)

main <- function() {
  inventory <- 100
  demand <- 150
  cost <- 10
  supply <- 60
  supply_chain <- SupplyChain$new(inventory = inventory, demand = demand, cost = cost)
  optimizer <- Optimizer$new(supply_chain = supply_chain, supply = supply)
  result <- optimizer$optimize()
  cat(sprintf('Shortage: %d, Fulfilled: %d, Cost: %d\n', result$shortage, result$fulfilled, result$cost))
}

main()