SignalProcessor <- R6::R6Class("SignalProcessor",
  public = list(
    data = NULL,
    index = 0,
    initialize = function(data) {
      self$data <- data
      self$index <- 0
    },
    process = function() {
      if (self$index < length(self$data)) {
        self$data[self$index + 1] <- self$filter(self$data[self$index + 1])
        self$index <- self$index + 1
        self$process()
      }
    },
    filter = function(value) {
      return(value * 2)
    }
  )
)

RecursiveAnalyzer <- R6::R6Class("RecursiveAnalyzer",
  public = list(
    data = NULL,
    index = 0,
    initialize = function(data) {
      self$data <- data
      self$index <- 0
    },
    analyze = function() {
      if (self$index < length(self$data)) {
        self$data[self$index + 1] <- self$transform(self$data[self$index + 1])
        self$index <- self$index + 1
        self$analyze()
      }
    },
    transform = function(value) {
      return(value + 1)
    }
  )
)

RecursiveModifier <- R6::R6Class("RecursiveModifier",
  public = list(
    data = NULL,
    index = 0,
    initialize = function(data) {
      self$data <- data
      self$index <- 0
    },
    modify = function() {
      if (self$index < length(self$data)) {
        self$data[self$index + 1] <- self$adjust(self$data[self$index + 1])
        self$index <- self$index + 1
        self$modify()
      }
    },
    adjust = function(value) {
      return(value - 1)
    }
  )
)

main <- function() {
  initial_data <- c(1, 2, 3, 4, 5)
  processor <- SignalProcessor$new(initial_data)
  analyzer <- RecursiveAnalyzer$new(initial_data)
  modifier <- RecursiveModifier$new(initial_data)
  processor$process()
  analyzer$analyze()
  modifier$modify()
  main()
}

main()