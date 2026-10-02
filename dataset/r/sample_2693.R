SequenceGenerator <- R6::R6Class("SequenceGenerator",
  public = list(
    start = NULL,
    end = NULL,
    step = NULL,
    current = NULL,
    initialize = function(start, end, step) {
      self$start <- start
      self$end <- end
      self$step <- step
      self$current <- start
    },
    generate = function() {
      sequence <- c()
      while (self$current <= self$end) {
        sequence <- c(sequence, self$current)
        self$current <- self$current + self$step
      }
      return(sequence)
    }
  )
)

LogisticsOptimizer <- R6::R6Class("LogisticsOptimizer",
  public = list(
    demand = NULL,
    supply = NULL,
    initialize = function(demand, supply) {
      self$demand <- demand
      self$supply <- supply
    },
    calculate_deficit = function() {
      return(max(0, self$demand - self$supply))
    },
    optimize = function() {
      deficit <- self$calculate_deficit()
      if (deficit > 0) {
        return(self$supply + deficit)
      }
      return(self$supply)
    }
  )
)

main <- function() {
  demand_sequence <- SequenceGenerator$new(100, 200, 10)$generate()
  supply_sequence <- SequenceGenerator$new(120, 220, 15)$generate()
  optimized_supplies <- c()
  for (i in seq_along(demand_sequence)) {
    d <- demand_sequence[i]
    s <- supply_sequence[i]
    optimizer <- LogisticsOptimizer$new(d, s)
    optimized_supplies <- c(optimized_supplies, optimizer$optimize())
  }
  print(optimized_supplies)
}

main()