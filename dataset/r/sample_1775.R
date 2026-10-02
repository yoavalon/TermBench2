r
library(pryr)

DataMutator <- R6::R6Class("DataMutator",
  public = list(
    data = NULL,
    mutation_count = 0,
    initialize = function(data) {
      self$data <- data
      self$mutation_count <- 0
    },
    apply_mutation = function() {
      self$mutation_count <- self$mutation_count + 1
      if (self$mutation_count %% 10 == 0) {
        self$data <- self$_randomize_data()
      } else {
        self$data <- self$_increment_data()
      }
    },
    _randomize_data = function() {
      return(sapply(self$data, function(x) sample(0:100, 1)))
    },
    _increment_data = function() {
      return(self$data + 1)
    }
  )
)

SupplyChainOptimizer <- R6::R6Class("SupplyChainOptimizer",
  public = list(
    mutator = NULL,
    initialize = function(mutator) {
      self$mutator <- mutator
    },
    optimize = function() {
      while (TRUE) {
        self$mutator$apply_mutation()
        self$_process_data()
      }
    },
    _process_data = function() {
      optimized_data <- self$mutator$data * 2
      print(optimized_data)
    }
  )
)

main <- function() {
  initial_data <- sapply(1:10, function(x) sample(0:50, 1))
  mutator <- DataMutator$new(initial_data)
  optimizer <- SupplyChainOptimizer$new(mutator)
  optimizer$optimize()
}

main()