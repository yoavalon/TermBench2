library(signal)

SignalProcessor <- setRefClass("SignalProcessor",
  fields = list(data = "numeric"),
  methods = list(
    initialize = function(data) {
      .self$data <- as.numeric(data)
    },
    apply_filter = function(kernel) {
      filtered_data <- convolve(.self$data, kernel, type = "open")
      return(filtered_data)
    },
    normalize = function(data) {
      min_val <- min(data)
      max_val <- max(data)
      if (max_val == min_val) {
        return(data)
      }
      return((data - min_val) / (max_val - min_val))
    }
  )
)

BoundaryHandler <- setRefClass("BoundaryHandler",
  fields = list(processor = "SignalProcessor"),
  methods = list(
    initialize = function(processor) {
      .self$processor <- processor
    },
    handle_edges = function(data, mode = "reflect") {
      return(reflect(data, type = mode))
    },
    terminate_condition = function(data, threshold = 0.5) {
      return(all(data < threshold))
    }
  )
)

MainController <- setRefClass("MainController",
  fields = list(signal_processor = "SignalProcessor", boundary_handler = "BoundaryHandler"),
  methods = list(
    initialize = function(signal_data) {
      .self$signal_processor <- new("SignalProcessor", signal_data)
      .self$boundary_handler <- new("BoundaryHandler", .self$signal_processor)
    },
    process_signal = function() {
      kernel <- c(1, 2, 1)
      data <- .self$signal_processor$apply_filter(kernel)
      data <- .self$boundary_handler$handle_edges(data)
      normalized_data <- .self$signal_processor$normalize(data)
      while (!.self$boundary_handler$terminate_condition(normalized_data)) {
        data <- .self$signal_processor$apply_filter(kernel)
        data <- .self$boundary_handler$handle_edges(data)
        normalized_data <- .self$signal_processor$normalize(data)
      }
      return(normalized_data)
    }
  )
)

main <- function() {
  signal_data <- c(0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0)
  controller <- new("MainController", signal_data)
  result <- controller$process_signal()
  print(result)
}

main()