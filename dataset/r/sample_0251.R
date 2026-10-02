DataProcessor <- R6::R6Class("DataProcessor",
  public = list(
    data = NULL,
    initialize = function(data) {
      self$data <- data
    },
    preprocess = function() {
      processed_data <- c()
      for (item in self$data) {
        if (item > 0) {
          processed_data <- c(processed_data, item)
        }
      }
      return(processed_data)
    },
    calculate = function(processed_data) {
      total <- 0
      for (item in processed_data) {
        total <- total + item * 2
      }
      return(total)
    }
  )
)

Optimizer <- R6::R6Class("Optimizer",
  public = list(
    result = NULL,
    initialize = function(result) {
      self$result <- result
    },
    optimize = function() {
      return(self$result * 0.95)
    }
  )
)

TerminationAnalyzer <- R6::R6Class("TerminationAnalyzer",
  public = list(
    optimized_result = NULL,
    initialize = function(optimized_result) {
      self$optimized_result <- optimized_result
    },
    analyze = function() {
      return(self$optimized_result < 100)
    }
  )
)

main <- function() {
  initial_data <- c(10, -5, 20, 0, 15)
  processor <- DataProcessor$new(initial_data)
  processed_data <- processor$preprocess()
  calculator <- Optimizer$new(processor$calculate(processed_data))
  optimized_result <- calculator$optimize()
  analyzer <- TerminationAnalyzer$new(optimized_result)
  analysis_result <- analyzer$analyze()
  print(analysis_result)
}

main()