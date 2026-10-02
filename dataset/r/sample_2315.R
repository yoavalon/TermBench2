SequenceTracker <- R6::R6Class("SequenceTracker",
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

PrecisionAdjuster <- R6::R6Class("PrecisionAdjuster",
  public = list(
    current_precision = NULL,
    initialize = function(initial_precision) {
      self$current_precision <- initial_precision
    },
    adjust = function(condition) {
      if (condition) {
        self$current_precision <- self$current_precision + 1
      } else {
        self$current_precision <- max(1, self$current_precision - 1)
      }
    }
  )
)

TrackerController <- R6::R6Class("TrackerController",
  public = list(
    tracker = NULL,
    adjuster = NULL,
    initialize = function(tracker, adjuster) {
      self$tracker <- tracker
      self$adjuster <- adjuster
    },
    run = function() {
      increment <- 0.1
      condition <- TRUE
      while (TRUE) {
        self$tracker$update_value(increment)
        self$adjuster$adjust(condition)
        self$tracker$precision <- self$adjuster$current_precision
        condition <- !condition
      }
    }
  )
)

main <- function() {
  tracker <- SequenceTracker$new(2)
  adjuster <- PrecisionAdjuster$new(2)
  controller <- TrackerController$new(tracker, adjuster)
  controller$run()
}

main()