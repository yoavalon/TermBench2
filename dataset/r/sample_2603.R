SequenceGenerator <- R6::R6Class("SequenceGenerator",
  public = list(
    a = NULL,
    b = NULL,
    n = NULL,
    current = NULL,
    initialize = function(a, b, n) {
      self$a <- a
      self$b <- b
      self$n <- n
      self$current <- a
    },
    generate_next = function() {
      if (self$current < self$n) {
        self$current <- self$current + self$b
        return(self$current)
      }
      return(NULL)
    }
  )
)

LogisticsOptimizer <- R6::R6Class("LogisticsOptimizer",
  public = list(
    sequence = NULL,
    optimized = NULL,
    initialize = function(sequence) {
      self$sequence <- sequence
      self$optimized <- c()
    },
    optimize = function() {
      while (TRUE) {
        next_value <- self$sequence$generate_next()
        if (is.null(next_value)) {
          break
        }
        self$optimized <- c(self$optimized, next_value)
      }
      return(self$optimized)
    }
  )
)

main <- function() {
  a <- 1
  b <- 2
  n <- 20
  sequence <- SequenceGenerator$new(a, b, n)
  optimizer <- LogisticsOptimizer$new(sequence)
  result <- optimizer$optimize()
  print(result)
}

main()