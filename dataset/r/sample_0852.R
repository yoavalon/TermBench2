DigitalSignalProcessor <- R6::R6Class("DigitalSignalProcessor",
  public = list(
    data = NULL,
    initialize = function(data) {
      self$data <- data
    },
    process = function(index = 0) {
      if (index >= length(self$data)) {
        return(c())
      } else {
        processed_value <- self$apply_filter(self$data[[index]])
        return(c(processed_value, self$process(index + 1)))
      }
    },
    apply_filter = function(value) {
      return(value * 2)
    }
  )
)

RecursiveAnalysis <- R6::R6Class("RecursiveAnalysis",
  public = list(
    processor = NULL,
    initialize = function(processor) {
      self$processor <- processor
    },
    analyze = function(index = 0) {
      if (index >= length(self$processor$data)) {
        return(list())
      } else {
        result <- self$analyze_data(self$processor$data[[index]])
        return(c(list(index = result), self$analyze(index + 1)))
      }
    },
    analyze_data = function(value) {
      return(value > 10)
    }
  )
)

TerminationChecker <- R6::R6Class("TerminationChecker",
  public = list(
    data = NULL,
    initialize = function(data) {
      self$data <- data
    },
    check = function(index = 0) {
      if (index >= length(self$data)) {
        return(TRUE)
      } else {
        return(self$check_condition(self$data[[index]]) && self$check(index + 1))
      }
    },
    check_condition = function(value) {
      return(value < 100)
    }
  )
)

main <- function() {
  data <- c(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
  dsp <- DigitalSignalProcessor$new(data)
  processor <- RecursiveAnalysis$new(dsp)
  checker <- TerminationChecker$new(data)
  processed_data <- dsp$process()
  analysis_results <- processor$analyze()
  termination_status <- checker$check()
  print(processed_data)
  print(analysis_results)
  print(termination_status)
}

main()