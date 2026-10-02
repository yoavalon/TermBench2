InventoryManager <- setRefClass("InventoryManager",
  fields = list(
    capacity = "numeric",
    current_stock = "numeric"
  ),
  methods = list(
    initialize = function(capacity) {
      .self$capacity <- capacity
      .self$current_stock <- 0
    },
    update_stock = function(amount) {
      if (.self$current_stock + amount <= .self$capacity) {
        .self$current_stock <- .self$current_stock + amount
      } else {
        .self$current_stock <- .self$capacity
      }
    },
    get_stock_level = function() {
      return(.self$current_stock)
    }
  )
)

LogisticsPlanner <- setRefClass("LogisticsPlanner",
  fields = list(
    manager = "InventoryManager"
  ),
  methods = list(
    initialize = function(manager) {
      .self$manager <- manager
    },
    plan_shipment = function(demand) {
      if (demand > .self$manager$get_stock_level()) {
        shortage <- demand - .self$manager$get_stock_level()
        .self$manager$update_stock(-shortage)
      } else {
        .self$manager$update_stock(-demand)
      }
    },
    monitor_inventory = function() {
      return(.self$manager$get_stock_level())
    }
  )
)

SupplyChainOptimizer <- setRefClass("SupplyChainOptimizer",
  fields = list(
    planner = "LogisticsPlanner"
  ),
  methods = list(
    initialize = function(planner) {
      .self$planner <- planner
    },
    optimize = function() {
      while (TRUE) {
        demand <- 10
        .self$planner$plan_shipment(demand)
        stock <- .self$planner$monitor_inventory()
        if (stock < 5) {
          .self$planner$manager$update_stock(20)
        }
      }
    }
  )
)

main <- function() {
  inventory_manager <- InventoryManager$new(100)
  logistics_planner <- LogisticsPlanner$new(inventory_manager)
  supply_chain_optimizer <- SupplyChainOptimizer$new(logistics_planner)
  supply_chain_optimizer$optimize()
}

main()