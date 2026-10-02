SequenceGenerator <- R6::R6Class("SequenceGenerator",
  public = list(
    a = NULL,
    b = NULL,
    current = NULL,
    initialize = function(a, b) {
      self$a <- a
      self$b <- b
      self$current <- a
    },
    next = function() {
      self$current <- self$current + self$b
      return(self$current)
    }
  )
)

InventoryOptimizer <- R6::R6Class("InventoryOptimizer",
  public = list(
    stock = NULL,
    demand_sequence = NULL,
    current_demand = NULL,
    initialize = function(initial_stock, demand_sequence) {
      self$stock <- initial_stock
      self$demand_sequence <- demand_sequence
      self$current_demand <- 0
    },
    update_stock = function(supply) {
      self$stock <- self$stock + supply
    },
    process_demand = function() {
      self$current_demand <- self$demand_sequence$next()
      if (self$stock >= self$current_demand) {
        self$stock <- self$stock - self$current_demand
      } else {
        self$stock <- 0
      }
    }
  )
)

SupplyChainSimulator <- R6::R6Class("SupplyChainSimulator",
  public = list(
    inventory_optimizer = NULL,
    supply_sequence = NULL,
    initialize = function(initial_stock, demand_a, demand_b, supply_a, supply_b) {
      self$inventory_optimizer <- InventoryOptimizer$new(initial_stock, SequenceGenerator$new(demand_a, demand_b))
      self$supply_sequence <- SequenceGenerator$new(supply_a, supply_b)
    },
    run = function() {
      while (TRUE) {
        supply <- self$supply_sequence$next()
        self$inventory_optimizer$update_stock(supply)
        self$inventory_optimizer$process_demand()
      }
    }
  )
)

main <- function() {
  initial_stock <- 100
  demand_a <- 10
  demand_b <- 5
  supply_a <- 20
  supply_b <- 10
  simulator <- SupplyChainSimulator$new(initial_stock, demand_a, demand_b, supply_a, supply_b)
  simulator$run()
}

main()