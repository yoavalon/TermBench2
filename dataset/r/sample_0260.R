library(stats)

Filter <- setRefClass("Filter",
  fields = list(coeffs = "numeric", state = "numeric"),
  methods = list(
    initialize = function(coefficients) {
      .self$coeffs <- coefficients
      .self$state <- rep(0, length(coefficients) - 1)
    },
    apply = function(signal) {
      output <- filter(signal, .self$coeffs, sides = 1)
      .self$update_state(signal, output)
      return(output[(length(coefficients) - 1):length(signal)])
    },
    update_state = function(signal, output) {
      new_state <- c(tail(signal, length(.self$coeffs) - 1), output)
      .self$state <- tail(new_state, length(.self$coeffs) - 1)
    }
  )
)

BoundaryProcessor <- setRefClass("BoundaryProcessor",
  fields = list(filter = "Filter", boundaries = "numeric"),
  methods = list(
    initialize = function(filter_obj, boundary_values) {
      .self$filter <- filter_obj
      .self$boundaries <- boundary_values
    },
    process = function(data) {
      filtered_data <- .self$filter$apply(data)
      clipped_data <- .self$clip(filtered_data)
      return(clipped_data)
    },
    clip = function(data) {
      return(pmin(pmax(data, .self$boundaries[1]), .self$boundaries[2]))
    }
  )
)

DataAnalyzer <- setRefClass("DataAnalyzer",
  fields = list(processor = "BoundaryProcessor"),
  methods = list(
    initialize = function(processor_obj) {
      .self$processor <- processor_obj
    },
    analyze = function(input_data) {
      processed_data <- .self$processor$process(input_data)
      return(processed_data)
    }
  )
)

main <- function() {
  coefficients <- c(0.05, 0.1, 0.2, 0.1, 0.05)
  filter_obj <- Filter$new(coefficients)
  boundary_values <- c(-1, 1)
  processor <- BoundaryProcessor$new(filter_obj, boundary_values)
  analyzer <- DataAnalyzer$new(processor)
  input_data <- rnorm(1000)
  result <- analyzer$analyze(input_data)
  print(result)
}

main()