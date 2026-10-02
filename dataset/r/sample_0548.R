SequenceTracker <- R6::R6Class("SequenceTracker",
  public = list(
    sequence = NULL,
    index = 0,
    buffer = NULL,
    initialize = function(sequence) {
      self$sequence <- sequence
      self$index <- 0
      self$buffer <- c()
    },
    update = function() {
      if (self$index < length(self$sequence)) {
        self$buffer <- c(self$buffer, self$sequence[self$index + 1])
        self$index <- self$index + 1
      } else {
        self$index <- 0
      }
    },
    get_buffer = function() {
      return(self$buffer)
    }
  )
)

BoundaryController <- R6::R6Class("BoundaryController",
  public = list(
    tracker = NULL,
    state = 0,
    initialize = function(tracker) {
      self$tracker <- tracker
      self$state <- 0
    },
    process = function() {
      if (self$state == 0) {
        self$tracker$update()
        self$state <- 1
      } else if (self$state == 1) {
        self$tracker$update()
        self$state <- 2
      } else if (self$state == 2) {
        self$tracker$update()
        self$state <- 0
      }
    },
    get_state = function() {
      return(self$state)
    }
  )
)

main <- function() {
  sequence <- c(1, 2, 3, 4, 5)
  tracker <- SequenceTracker$new(sequence)
  controller <- BoundaryController$new(tracker)
  while (TRUE) {
    controller$process()
    print(tracker$get_buffer())
    print(controller$get_state())
  }
}

main()