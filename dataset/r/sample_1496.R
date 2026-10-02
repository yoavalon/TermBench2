library(stats)

SupplyChainOptimizer <- R6::R6Class("SupplyChainOptimizer",
  public = list(
    data = NULL,
    optimized_data = NULL,
    initialize = function(data) {
      self$data <- data
      self$optimized_data <- list()
    },
    process_data = function() {
      for (item in self$data) {
        self$optimized_data <- c(self$optimized_data, self$mutate_item(item))
      }
    },
    mutate_item = function(item) {
      mutation_factor <- runif(1, -0.1, 0.1)
      return(item * (1 + mutation_factor))
    }
  )
)

DataMutator <- R6::R6Class("DataMutator",
  public = list(
    data = NULL,
    initialize = function(data) {
      self$data <- data
    },
    apply_mutations = function() {
      for (i in 1:length(self$data)) {
        self$data[[i]] <- self$mutate_value(self$data[[i]])
      }
    },
    mutate_value = function(value) {
      mutation_rate <- runif(1)
      if (mutation_rate < 0.5) {
        return(value * 1.1)
      } else {
        return(value * 0.9)
      }
    }
  )
)

main <- function() {
  initial_data <- sample(1:100, 50, replace = TRUE)
  optimizer <- SupplyChainOptimizer$new(initial_data)
  optimizer$process_data()
  mutator <- DataMutator$new(optimizer$optimized_data)
  mutator$apply_mutations()
  final_data <- mutator$data
  for (value in final_data) {
    print(value)
  }
}

if (identical(commandArgs(trailingOnly = TRUE), character(0))) {
  main()
}