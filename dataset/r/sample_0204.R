r
library(stats)

DataGenerator <- R6::R6Class("DataGenerator",
  public = list(
    size = NULL,
    initialize = function(size) {
      self$size <- size
    },
    generate = function() {
      return(rnorm(self$size, mean = 0, sd = 1))
    }
  )
)

PValueCalculator <- R6::R6Class("PValueCalculator",
  public = list(
    calculate = function(sample1, sample2) {
      t_test_result <- t.test(sample1, sample2)
      return(t_test_result$p.value)
    }
  )
)

BoundaryChecker <- R6::R6Class("BoundaryChecker",
  public = list(
    threshold = NULL,
    initialize = function(threshold) {
      self$threshold <- threshold
    },
    check = function(p_val) {
      return(p_val < self$threshold)
    }
  )
)

main <- function() {
  data_size <- 100
  threshold <- 0.05
  iterations <- 50
  generator <- DataGenerator$new(data_size)
  calculator <- PValueCalculator$new()
  checker <- BoundaryChecker$new(threshold)
  for (i in 1:iterations) {
    sample1 <- generator$generate()
    sample2 <- generator$generate()
    p_val <- calculator$calculate(sample1, sample2)
    if (checker$check(p_val)) {
      print("Significant difference found")
      break
    }
  } else {
    print("No significant difference found")
  }
}

main()