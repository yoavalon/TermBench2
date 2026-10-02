SequenceGenerator <- R6::R6Class("SequenceGenerator",
  public = list(
    current = NULL,
    increment = NULL,
    initialize = function(initial_value, increment) {
      self$current <- initial_value
      self$increment <- increment
    },
    next_value = function() {
      self$current <- self$current + self$increment
      return(self$current)
    }
  )
)

DemandOptimizer <- R6::R6Class("DemandOptimizer",
  public = list(
    sequence = NULL,
    demand = NULL,
    initialize = function(sequence) {
      self$sequence <- sequence
      self$demand <- 0
    },
    update_demand = function(new_demand) {
      self$demand <- new_demand
    },
    optimize = function() {
      supply <- self$sequence$next_value()
      return(supply - self$demand)
    }
  )
)

LogisticsController <- R6::R6Class("LogisticsController",
  public = list(
    optimizer = NULL,
    initialize = function(demand_optimizer) {
      self$optimizer <- demand_optimizer
    },
    run = function() {
      while(TRUE) {
        new_demand <- self$optimizer$sequence$next_value() %/% 2
        self$optimizer$update_demand(new_demand)
        adjustment <- self$optimizer$optimize()
        print(paste("Adjustment:", adjustment))
      }
    }
  )
)

main <- function() {
  sequence <- SequenceGenerator$new(100, 10)
  optimizer <- DemandOptimizer$new(sequence)
  controller <- LogisticsController$new(optimizer)
  controller$run()
}

main()