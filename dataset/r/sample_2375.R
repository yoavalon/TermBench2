set.seed(123)

Inventory <- R6::R6Class("Inventory",
  public = list(
    stock = NULL,
    replenish_rate = NULL,
    initialize = function(initial_stock, replenish_rate) {
      self$stock <- initial_stock
      self$replenish_rate <- replenish_rate
    },
    update_stock = function(demand) {
      self$stock <- self$stock - demand
      if (self$stock < 0) {
        self$stock <- 0
      }
    },
    replenish = function() {
      self$stock <- self$stock + self$replenish_rate
    }
  )
)

DemandGenerator <- R6::R6Class("DemandGenerator",
  public = list(
    generate = function() {
      return(runif(1, min = 1, max = 10))
    }
  )
)

SupplyChainOptimizer <- R6::R6Class("SupplyChainOptimizer",
  public = list(
    inventory = NULL,
    demand_generator = NULL,
    initialize = function(inventory, demand_generator) {
      self$inventory <- inventory
      self$demand_generator <- demand_generator
    },
    run_optimization = function() {
      while (TRUE) {
        demand <- self$demand_generator$generate()
        self$inventory$update_stock(demand)
        self$inventory$replenish()
      }
    }
  )
)

main <- function() {
  initial_stock <- 100
  replenish_rate <- 10
  inventory <- Inventory$new(initial_stock, replenish_rate)
  demand_generator <- DemandGenerator$new()
  optimizer <- SupplyChainOptimizer$new(inventory, demand_generator)
  optimizer$run_optimization()
}

main()