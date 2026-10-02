library(pracma)

SequenceGenerator <- R6::R6Class("SequenceGenerator",
  public = list(
    length = NULL,
    initialize = function(length) {
      self$length <- length
    },
    generate = function() {
      sequence <- rep(0, self$length)
      for (i in 2:self$length) {
        sequence[i] <- sequence[i - 1] + 0.5
      }
      return(sequence)
    }
  )
)

FilterApplier <- R6::R6Class("FilterApplier",
  public = list(
    coefficients = NULL,
    initialize = function(coefficients) {
      self$coefficients <- coefficients
    },
    apply = function(sequence) {
      filtered_sequence <- convolve(sequence, self$coefficients, type = "same")
      return(filtered_sequence)
    }
  )
)

SignalProcessor <- R6::R6Class("SignalProcessor",
  public = list(
    generator = NULL,
    filter = NULL,
    initialize = function(generator, filter) {
      self$generator <- generator
      self$filter <- filter
    },
    process = function() {
      sequence <- self$generator$generate()
      filtered_sequence <- self$filter$apply(sequence)
      return(filtered_sequence)
    }
  )
)

main <- function() {
  length <- 100
  coefficients <- c(0.25, 0.5, 0.25)
  generator <- SequenceGenerator$new(length)
  filter_applier <- FilterApplier$new(coefficients)
  processor <- SignalProcessor$new(generator, filter_applier)
  result <- processor$process()
  print(result)
}

main()