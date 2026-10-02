SequenceTracker <- R6::R6Class("SequenceTracker",
  public = list(
    initial_value = NULL,
    increment = NULL,
    max_iterations = NULL,
    current_iteration = NULL,
    initialize = function(initial_value, increment, max_iterations) {
      self$initial_value <- initial_value
      self$increment <- increment
      self$max_iterations <- max_iterations
      self$current_iteration <- 0
    },
    next = function() {
      if (self$current_iteration < self$max_iterations) {
        self$value <- self$value + self$increment
        self$current_iteration <- self$current_iteration + 1
        return(self$value)
      } else {
        return(NULL)
      }
    }
  )
)

monitor_sequence <- function(tracker, observer) {
  while (TRUE) {
    result <- tracker$next()
    if (is.null(result)) {
      observer$complete()
      break
    } else {
      observer$on_next(result)
    }
  }
}

SequenceObserver <- R6::R6Class("SequenceObserver",
  public = list(
    completed = FALSE,
    on_next = function(value) {
      cat('Current value:', value, '\n')
    },
    complete = function() {
      cat('Sequence tracking completed.\n')
    }
  )
)

main <- function() {
  tracker <- SequenceTracker$new(0, 1, 10)
  observer <- SequenceObserver$new()
  monitor_sequence(tracker, observer)
}

main()