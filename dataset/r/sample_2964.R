SequenceGenerator <- R6::R6Class(
  "SequenceGenerator",
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

DemandOptimizer <- R6::R6Class(
  "DemandOptimizer",
  public = list(
    sequence = NULL,
    current_demand = NULL,
    initialize = function(sequence) {
      self$sequence <- sequence
      self$current_demand <- 0
    },
    update_demand = function(new_demand) {
      self$current_demand <- new_demand
    },
    optimize = function() {
      optimal_value <- self$sequence$next()
      while (optimal_value < self$current_demand) {
        optimal_value <- self$sequence$next()
      }
      return(optimal_value)
    }
  )
)

LogisticsSystem <- R6::R6Class(
  "LogisticsSystem",
  public = list(
    sequence_generator = NULL,
    demand_optimizer = NULL,
    initialize = function(initial_value, increment, initial_demand) {
      self$sequence_generator <- SequenceGenerator$new(initial_value, increment)
      self$demand_optimizer <- DemandOptimizer$new(self$sequence_generator)
      self$demand_optimizer$update_demand(initial_demand)
    },
    run = function() {
      while (TRUE) {
        optimized_value <- self$demand_optimizer$optimize()
        cat('Optimized Value:', optimized_value, '\n')
        self$demand_optimizer$update_demand(optimized_value + 10)
      }
    }
  )
)

main <- function() {
  logistics_system <- LogisticsSystem$new(100, 5, 150)
  logistics_system$run()
}

main()