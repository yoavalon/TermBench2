SupplyChain <- R6::R6Class("SupplyChain",
  public = list(
    inventory = NULL,
    demand = NULL,
    cost = NULL,
    capacity = NULL,
    initialize = function(inventory, demand, cost, capacity) {
      self$inventory <- inventory
      self$demand <- demand
      self$cost <- cost
      self$capacity <- capacity
    },
    calculate_profit = function() {
      supply <- min(self$inventory, self$capacity)
      revenue <- supply * self$demand
      expenses <- supply * self$cost
      return(revenue - expenses)
    },
    update_inventory = function() {
      self$inventory <- self$inventory - min(self$inventory, self$capacity)
    }
  )
)

LogisticsOptimizer <- R6::R6Class("LogisticsOptimizer",
  public = list(
    supply_chain = NULL,
    initialize = function(supply_chain) {
      self$supply_chain <- supply_chain
    },
    optimize = function() {
      while(TRUE) {
        profit <- self$supply_chain$calculate_profit()
        self$supply_chain$update_inventory()
        if (profit > 0) {
          self$supply_chain$capacity <- self$supply_chain$capacity + 1
        } else {
          self$supply_chain$capacity <- self$supply_chain$capacity - 1
        }
      }
    }
  )
)

main <- function() {
  initial_inventory <- 1000
  demand_rate <- 50
  production_cost <- 10
  initial_capacity <- 150
  supply_chain <- SupplyChain$new(initial_inventory, demand_rate, production_cost, initial_capacity)
  optimizer <- LogisticsOptimizer$new(supply_chain)
  optimizer$optimize()
}

main()