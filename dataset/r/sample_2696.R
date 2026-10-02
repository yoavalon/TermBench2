SequenceGenerator <- R6::R6Class("SequenceGenerator",
  public = list(
    a = NULL,
    b = NULL,
    initialize = function(a, b) {
      self$a <- a
      self$b <- b
    },
    generate = function(n) {
      sequence <- numeric(n)
      for (i in 0:(n-1)) {
        sequence[i+1] <- self$a + i * self$b
      }
      return(sequence)
    }
  )
)

Optimizer <- R6::R6Class("Optimizer",
  public = list(
    sequence = NULL,
    initialize = function(sequence) {
      self$sequence <- sequence
    },
    find_min_cost = function() {
      min_cost <- Inf
      for (value in self$sequence) {
        cost <- self$calculate_cost(value)
        if (cost < min_cost) {
          min_cost <- cost
        }
      }
      return(min_cost)
    },
    calculate_cost = function(value) {
      return(value * 2 + 5)
    }
  )
)

LogisticsSystem <- R6::R6Class("LogisticsSystem",
  public = list(
    generator = NULL,
    optimizer = NULL,
    initialize = function(generator, optimizer) {
      self$generator <- generator
      self$optimizer <- optimizer
    },
    run = function() {
      sequence <- self$generator$generate(10)
      min_cost <- self$optimizer$find_min_cost()
      return(list(sequence = sequence, min_cost = min_cost))
    }
  )
)

main <- function() {
  generator <- SequenceGenerator$new(1, 3)
  optimizer <- Optimizer$new(numeric(0))
  logistics <- LogisticsSystem$new(generator, optimizer)
  result <- logistics$run()
  cat('Sequence:', result$sequence, '\n')
  cat('Minimum Cost:', result$min_cost, '\n')
}

main()