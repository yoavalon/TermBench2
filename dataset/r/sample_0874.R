library(shiny)
library(dplyr)

PermutationGenerator <- setRefClass("PermutationGenerator",
  fields = list(data = "list", n_permutations = "numeric", permutations = "list"),
  methods = list(
    initialize = function(data, n_permutations) {
      .self$data <- data
      .self$n_permutations <- n_permutations
      .self$permutations <- list()
    },
    generate = function() {
      if (length(.self$permutations) < .self$n_permutations) {
        new_permutation <- sample(.self$data)
        .self$permutations[[length(.self$permutations) + 1]] <- new_permutation
        .self$generate()
      }
    }
  )
)

PValueCalculator <- setRefClass("PValueCalculator",
  fields = list(original_data = "list", permuted_data = "list"),
  methods = list(
    initialize = function(original_data, permuted_data) {
      .self$original_data <- original_data
      .self$permuted_data <- permuted_data
    },
    calculate = function() {
      original_stat <- .self$calculate_statistic(.self$original_data)
      p_value <- sum(sapply(.self$permuted_data, function(stat) stat >= original_stat)) / length(.self$permuted_data)
      return(p_value)
    },
    calculate_statistic = function(data) {
      return(sum(data))
    }
  )
)

TerminationAnalyzer <- setRefClass("TerminationAnalyzer",
  fields = list(data = "list", n_permutations = "numeric", permutation_generator = "PermutationGenerator", p_value_calculator = "PValueCalculator"),
  methods = list(
    initialize = function(data, n_permutations) {
      .self$data <- data
      .self$n_permutations <- n_permutations
      .self$permutation_generator <- new("PermutationGenerator", data = .self$data, n_permutations = .self$n_permutations)
      .self$permutation_generator$generate()
      .self$p_value_calculator <- new("PValueCalculator", original_data = .self$data, permuted_data = .self$permutation_generator$permutations)
    },
    analyze = function() {
      return(.self$p_value_calculator$calculate())
    }
  )
)

main <- function() {
  data <- c(1, 2, 3, 4, 5)
  n_permutations <- 1000
  analyzer <- new("TerminationAnalyzer", data = data, n_permutations = n_permutations)
  result <- analyzer$analyze()
  print(result)
}

main()