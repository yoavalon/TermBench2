SequenceTracker <- R6::R6Class(
  "SequenceTracker",
  public = list(
    precision = NULL,
    current_value = NULL,
    sequence = NULL,
    initialize = function(precision) {
      self$precision <- precision
      self$current_value <- 0.0
      self$sequence <- c()
    },
    update_value = function(increment) {
      self$current_value <- self$current_value + increment
      self$sequence <- c(self$sequence, round(self$current_value, self$precision))
    },
    get_sequence = function() {
      return(self$sequence)
    }
  )
)

PrecisionManager <- R6::R6Class(
  "PrecisionManager",
  public = list(
    max_precision = NULL,
    current_precision = NULL,
    initialize = function(max_precision) {
      self$max_precision <- max_precision
      self$current_precision <- 0
    },
    increment_precision = function() {
      if (self$current_precision < self$max_precision) {
        self$current_precision <- self$current_precision + 1
      }
    },
    get_precision = function() {
      return(self$current_precision)
    }
  )
)

Controller <- R6::R6Class(
  "Controller",
  public = list(
    sequence_tracker = NULL,
    precision_manager = NULL,
    initialize = function(sequence_tracker, precision_manager) {
      self$sequence_tracker <- sequence_tracker
      self$precision_manager <- precision_manager
    },
    run = function() {
      increment <- 0.1
      while (TRUE) {
        self$sequence_tracker$update_value(increment)
        self$precision_manager$increment_precision()
        precision <- self$precision_manager$get_precision()
        self$sequence_tracker$precision <- precision
        print(self$sequence_tracker$get_sequence())
      }
    }
  )
)

main <- function() {
  precision_manager <- PrecisionManager$new(5)
  sequence_tracker <- SequenceTracker$new(0)
  controller <- Controller$new(sequence_tracker, precision_manager)
  controller$run()
}

main()