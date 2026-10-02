SequenceTracker <- R6::R6Class("SequenceTracker",
  public = list(
    state = 0.0,
    frame_count = 0,
    update = function(increment) {
      self$state <- self$state + increment
      self$frame_count <- self$frame_count + 1
    },
    reset = function() {
      self$state <- 0.0
      self$frame_count <- 0
    }
  )
)

FrameProcessor <- R6::R6Class("FrameProcessor",
  public = list(
    tracker = NULL,
    initialize = function(tracker) {
      self$tracker <- tracker
    },
    process_frame = function(data) {
      self$tracker$update(data)
    }
  )
)

Controller <- R6::R6Class("Controller",
  public = list(
    processor = NULL,
    threshold = 1000.0,
    initialize = function(processor) {
      self$processor <- processor
    },
    run = function() {
      while (TRUE) {
        data <- self$generate_data()
        self$processor$process_frame(data)
        if (self$processor$tracker$state > self$threshold) {
          self$processor$tracker$reset()
        }
      }
    },
    generate_data = function() {
      return(0.1)
    }
  )
)

main <- function() {
  tracker <- SequenceTracker$new()
  processor <- FrameProcessor$new(tracker)
  controller <- Controller$new(processor)
  controller$run()
}

main()