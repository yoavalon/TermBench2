r
Simulation <- R6::R6Class("Simulation",
  public = list(
    a = NULL,
    b = NULL,
    c = NULL,
    initialize = function(a, b, c) {
      self$a <- a
      self$b <- b
      self$c <- c
    },
    calculate = function(x) {
      return(self$a * x^2 + self$b * x + self$c)
    }
  )
)

PrecisionAnalyzer <- R6::R6Class("PrecisionAnalyzer",
  public = list(
    simulation = NULL,
    initialize = function(simulation) {
      self$simulation <- simulation
    },
    analyze = function(x_values) {
      results <- list()
      for (x in x_values) {
        result <- self$simulation$calculate(x)
        results <- c(results, result)
      }
      return(results)
    }
  )
)

DataProcessor <- R6::R6Class("DataProcessor",
  public = list(
    analyzer = NULL,
    initialize = function(analyzer) {
      self$analyzer <- analyzer
    },
    process = function(x_values) {
      raw_data <- self$analyzer$analyze(x_values)
      processed_data <- self$format_data(raw_data)
      return(processed_data)
    },
    format_data = function(data) {
      formatted <- list()
      for (value in data) {
        formatted <- c(formatted, round(value, 5))
      }
      return(formatted)
    }
  )
)

main <- function() {
  sim <- Simulation$new(2.0, 3.0, 1.0)
  analyzer <- PrecisionAnalyzer$new(sim)
  processor <- DataProcessor$new(analyzer)
  x_values <- c(0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0)
  processed_results <- processor$process(x_values)
  for (i in seq_along(processed_results)) {
    cat("X:", x_values[i], "Result:", processed_results[i], "\n")
  }
}

main()