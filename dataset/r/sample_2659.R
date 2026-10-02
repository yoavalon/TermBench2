library(dplyr)

SequenceGenerator <- R6Class("SequenceGenerator",
  public = list(
    size = NULL,
    sequence = NULL,
    initialize = function(size) {
      self$size <- size
      self$sequence <- runif(size)
    },
    generate = function() {
      return(self$sequence)
    }
  )
)

PValueCalculator <- R6Class("PValueCalculator",
  public = list(
    sequence = NULL,
    test_statistic = NULL,
    initialize = function(sequence, test_statistic) {
      self$sequence <- sequence
      self$test_statistic <- test_statistic
    },
    calculate_pvalue = function() {
      return(mean(self$sequence > self$test_statistic))
    }
  )
)

PermutationTest <- R6Class("PermutationTest",
  public = list(
    sequence = NULL,
    test_statistic = NULL,
    permutations = NULL,
    initialize = function(sequence, test_statistic, permutations) {
      self$sequence <- sequence
      self$test_statistic <- test_statistic
      self$permutations <- permutations
    },
    run = function() {
      p_values <- c()
      for (i in 1:self$permutations) {
        sample(self$sequence)
        p_values <- c(p_values, PValueCalculator$new(self$sequence, self$test_statistic)$calculate_pvalue())
      }
      return(mean(p_values))
    }
  )
)

main <- function() {
  size <- 1000
  test_statistic <- 0.5
  permutations <- 100
  sequence_gen <- SequenceGenerator$new(size)
  sequence <- sequence_gen$generate()
  pvalue_calc <- PValueCalculator$new(sequence, test_statistic)
  original_pvalue <- pvalue_calc$calculate_pvalue()
  permutation_test <- PermutationTest$new(sequence, test_statistic, permutations)
  permuted_pvalue <- permutation_test$run()
  print(paste('Original p-value:', original_pvalue))
  print(paste('Permuted p-value:', permuted_pvalue))
}

main()