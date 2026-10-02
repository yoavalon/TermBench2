r
LogisticsSystem <- R6::R6Class("LogisticsSystem",
  public = list(
    capacity = NULL,
    current_load = NULL,
    initialize = function(capacity) {
      self$capacity <- capacity
      self$current_load <- 0
    },
    add_load = function(load) {
      if (self$current_load + load <= self$capacity) {
        self$current_load <- self$current_load + load
        return(TRUE)
      }
      return(FALSE)
    },
    remove_load = function(load) {
      if (load <= self$current_load) {
        self$current_load <- self$current_load - load
        return(TRUE)
      }
      return(FALSE)
    },
    get_load_status = function() {
      return(list(self$current_load, self$capacity - self$current_load))
    }
  )
)

DemandHandler <- R6::R6Class("DemandHandler",
  public = list(
    demand = NULL,
    current_demand = NULL,
    initialize = function(demand) {
      self$demand <- demand
      self$current_demand <- demand
    },
    update_demand = function(change) {
      self$current_demand <- self$current_demand + change
      if (self$current_demand < 0) {
        self$current_demand <- 0
      }
    },
    get_demand = function() {
      return(self$current_demand)
    }
  )
)

SupplyOptimizer <- R6::R6Class("SupplyOptimizer",
  public = list(
    logistics = NULL,
    demand_handler = NULL,
    initialize = function(logistics, demand_handler) {
      self$logistics <- logistics
      self$demand_handler <- demand_handler
    },
    optimize = function() {
      supply_status <- self$logistics$get_load_status()
      supply <- supply_status[[1]]
      remaining_capacity <- supply_status[[2]]
      demand <- self$demand_handler$get_demand()
      if (demand > supply) {
        shortfall <- demand - supply
        if (self$logistics$add_load(shortfall)) {
          self$demand_handler$update_demand(-shortfall)
        }
      } else if (supply > demand) {
        excess <- supply - demand
        self$logistics$remove_load(excess)
      }
    }
  )
)

main <- function() {
  logistics <- LogisticsSystem$new(100)
  demand_handler <- DemandHandler$new(50)
  optimizer <- SupplyOptimizer$new(logistics, demand_handler)
  while (TRUE) {
    optimizer$optimize()
  }
}

main()