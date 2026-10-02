library(signal)

SignalProcessor <- R6::R6Class("SignalProcessor",
  public = list(
    data = NULL,
    length = NULL,
    initialize = function(data) {
      self$data <- data
      self$length <- length(data)
    },
    apply_filter = function(filter_coefficients) {
      filtered_data <- filter(self$data, filter_coefficients, method = "convolution", sides = 2)
      return(filtered_data)
    }
  )
)

BoundaryHandler <- R6::R6Class("BoundaryHandler",
  public = list(
    signal_processor = NULL,
    initialize = function(signal_processor) {
      self$signal_processor <- signal_processor
    },
    process_data = function() {
      filter_coefficients <- c(0.1, 0.2, 0.3, 0.2, 0.1)
      processed_data <- self$signal_processor$apply_filter(filter_coefficients)
      return(processed_data)
    }
  )
)

DataAnalyzer <- R6::R6Class("DataAnalyzer",
  public = list(
    boundary_handler = NULL,
    initialize = function(boundary_handler) {
      self$boundary_handler <- boundary_handler
    },
    analyze = function() {
      data <- self$boundary_handler$process_data()
      mean_value <- mean(data)
      max_value <- max(data)
      min_value <- min(data)
      return(list(mean_value, max_value, min_value))
    }
  )
)

main <- function() {
  data <- runif(1000)
  signal_processor <- SignalProcessor$new(data)
  boundary_handler <- BoundaryHandler$new(signal_processor)
  data_analyzer <- DataAnalyzer$new(boundary_handler)
  result <- data_analyzer$analyze()
  cat('Mean:', result[[1]], 'Max:', result[[2]], 'Min:', result[[3]], '\n')
}

main()