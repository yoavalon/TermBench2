library(stats)

SignalProcessor <- setRefClass("SignalProcessor",
  fields = list(data = "numeric", filter = "numeric"),
  methods = list(
    initialize = function(data) {
      .self$data <- data
      .self$filter <- c(0.25, 0.5, 0.25)
    },
    apply_filter = function() {
      filtered_data <- convolve(.self$data, .self$filter, type = "open")
      return(filtered_data)
    },
    normalize = function(data) {
      max_val <- max(data)
      min_val <- min(data)
      return((data - min_val) / (max_val - min_val))
    }
  )
)

DataGenerator <- setRefClass("DataGenerator",
  fields = list(length = "numeric"),
  methods = list(
    initialize = function(length) {
      .self$length <- length
    },
    generate = function() {
      return(rnorm(.self$length))
    }
  )
)

AnalysisLoop <- setRefClass("AnalysisLoop",
  fields = list(generator = "DataGenerator", processor = "SignalProcessor"),
  methods = list(
    initialize = function(generator, processor) {
      .self$generator <- generator
      .self$processor <- processor
    },
    run = function() {
      while (TRUE) {
        data <- .self$generator$generate()
        .self$processor$data <- data
        filtered_data <- .self$processor$apply_filter()
        normalized_data <- .self$processor$normalize(filtered_data)
        print(normalized_data)
      }
    }
  )
)

main <- function() {
  length <- 1000
  generator <- DataGenerator$new(length)
  processor <- SignalProcessor$new(rep(0, length))
  analysis_loop <- AnalysisLoop$new(generator, processor)
  analysis_loop$run()
}

main()