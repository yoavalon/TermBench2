SupplyChain <- setRefClass("SupplyChain",
  fields = list(
    inventory = "numeric",
    demand = "list",
    orders = "list",
    deliveries = "list"
  ),
  methods = list(
    initialize = function(inventory, demand) {
      .self$inventory <- inventory
      .self$demand <- demand
      .self$orders <- list()
      .self$deliveries <- list()
    },
    process_orders = function() {
      while (length(.self$orders) > 0) {
        order <- .self$orders[[1]]
        .self$orders <- .self$orders[-1]
        if (.self$inventory >= order) {
          .self$inventory <- .self$inventory - order
          .self$deliveries <- c(.self$deliveries, order)
        } else {
          .self$orders <- c(order, .self$orders)
        }
      }
    },
    receive_supply = function(supply) {
      .self$inventory <- .self$inventory + supply
    },
    handle_demand = function() {
      for (i in 1:length(.self$demand)) {
        if (length(.self$demand) > 0) {
          order <- .self$demand[[1]]
          .self$demand <- .self$demand[-1]
          .self$orders <- c(.self$orders, order)
        }
      }
    }
  )
)

LogisticsOptimizer <- setRefClass("LogisticsOptimizer",
  fields = list(
    supply_chain = "SupplyChain"
  ),
  methods = list(
    initialize = function(supply_chain) {
      .self$supply_chain <- supply_chain
    },
    optimize = function() {
      while (TRUE) {
        .self$supply_chain$handle_demand()
        .self$supply_chain$process_orders()
        if (length(.self$supply_chain$orders) > 0) {
          .self$supply_chain$receive_supply(sum(.self$supply_chain$orders))
        }
      }
    }
  )
)

main <- function() {
  inventory <- 100
  demand <- c(10, 20, 30, 40, 50, 60, 70, 80, 90, 100)
  supply_chain <- new("SupplyChain", inventory, demand)
  optimizer <- new("LogisticsOptimizer", supply_chain)
  optimizer$optimize()
}

main()