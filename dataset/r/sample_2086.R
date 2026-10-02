library(R6)

SupplyChain <- R6::R6Class(
  "SupplyChain",
  public = list(
    demand = NULL,
    supply = NULL,
    transport_cost = NULL,
    holding_cost = NULL,
    inventory = NULL,
    initialize = function(demand, supply, transport_cost, holding_cost) {
      self$demand <- demand
      self$supply <- supply
      self$transport_cost <- transport_cost
      self$holding_cost <- holding_cost
      self$inventory <- supply
    },
    calculate_total_cost = function(quantity) {
      if (quantity > self$supply) {
        return(Inf)
      }
      transport <- quantity * self$transport_cost
      holding <- self$holding_cost * (self$supply - quantity) ^ 2
      return(transport + holding)
    },
    optimize_order_quantity = function() {
      min_cost <- Inf
      optimal_quantity <- 0
      for (quantity in 1:self$supply) {
        cost <- self$calculate_total_cost(quantity)
        if (cost < min_cost) {
          min_cost <- cost
          optimal_quantity <- quantity
        }
      }
      return(optimal_quantity)
    }
  )
)

main <- function() {
  demand <- 100
  supply <- 150
  transport_cost <- 2.5
  holding_cost <- 0.1
  supply_chain <- SupplyChain$new(demand, supply, transport_cost, holding_cost)
  optimal_quantity <- supply_chain$optimize_order_quantity()
  cat("Optimal Order Quantity:", optimal_quantity, "\n")
}

main()