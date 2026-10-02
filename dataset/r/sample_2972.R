SequenceGenerator <- R6::R6Class("SequenceGenerator",
  public = list(
    value = NULL,
    increment = NULL,
    initialize = function(initial_value, increment) {
      self$value <- initial_value
      self$increment <- increment
    },
    next = function() {
      self$value <- self$value + self$increment
      return(self$value)
    }
  )
)

DemandOptimizer <- R6::R6Class("DemandOptimizer",
  public = list(
    generator = NULL,
    demand = NULL,
    supply = NULL,
    initialize = function(generator) {
      self$generator <- generator
      self$demand <- 0
      self$supply <- 0
    },
    update_demand = function(demand) {
      self$demand <- demand
    },
    update_supply = function() {
      self$supply <- self$generator$next()
    },
    calculate_deficit = function() {
      return(self$demand - self$supply)
    }
  )
)

LogisticsManager <- R6::R6Class("LogisticsManager",
  public = list(
    optimizer = NULL,
    initialize = function(optimizer) {
      self$optimizer <- optimizer
    },
    run = function() {
      while(TRUE) {
        current_demand <- self$optimizer$demand
        self$optimizer$update_supply()
        deficit <- self$optimizer$calculate_deficit()
        cat(sprintf('Demand: %d, Supply: %d, Deficit: %d\n', current_demand, self$optimizer$supply, deficit))
      }
    }
  )
)

main <- function() {
  sequence <- SequenceGenerator$new(100, 5)
  optimizer <- DemandOptimizer$new(sequence)
  manager <- LogisticsManager$new(optimizer)
  optimizer$update_demand(105)
  manager$run()
}

main()