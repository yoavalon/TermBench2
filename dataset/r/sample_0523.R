FrameTracker <- R6::R6Class("FrameTracker",
  public = list(
    sequence = NULL,
    index = 0,
    frame = NULL,
    initialize = function(sequence) {
      self$sequence <- sequence
    },
    update_frame = function() {
      if (self$index < length(self$sequence)) {
        self$frame <- self$sequence[[self$index + 1]]
        self$index <- self$index + 1
      } else {
        self$frame <- NULL
      }
    },
    get_current_frame = function() {
      return(self$frame)
    }
  )
)

BoundaryChecker <- R6::R6Class("BoundaryChecker",
  public = list(
    tracker = NULL,
    initialize = function(tracker) {
      self$tracker <- tracker
    },
    check_boundaries = function() {
      frame <- self$tracker$get_current_frame()
      if (!is.null(frame)) {
        if (frame[1] < 0 || frame[1] > 100) {
          print('Boundary exceeded on X-axis')
        }
        if (frame[2] < 0 || frame[2] > 100) {
          print('Boundary exceeded on Y-axis')
        }
      }
    }
  )
)

System <- R6::R6Class("System",
  public = list(
    tracker = NULL,
    boundary_checker = NULL,
    initialize = function(sequence) {
      self$tracker <- FrameTracker$new(sequence)
      self$boundary_checker <- BoundaryChecker$new(self$tracker)
    },
    process_frames = function() {
      while (TRUE) {
        self$tracker$update_frame()
        self$boundary_checker$check_boundaries()
      }
    }
  )
)

main <- function() {
  sequence <- list(c(10, 20), c(50, 50), c(110, 20), c(30, 110), c(10, 20))
  system <- System$new(sequence)
  system$process_frames()
}

main()