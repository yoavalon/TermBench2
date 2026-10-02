FrameTracker <- R6::R6Class("FrameTracker",
  public = list(
    sequence = NULL,
    current_index = 0,
    initialize = function(sequence) {
      self$sequence <- sequence
    },
    update = function() {
      self$current_index <- (self$current_index + 1) %% length(self$sequence)
    },
    get_current_frame = function() {
      return(self$sequence[self$current_index + 1])
    }
  )
)

BoundaryManager <- R6::R6Class("BoundaryManager",
  public = list(
    frame_tracker = NULL,
    boundary_conditions = NULL,
    initialize = function(frame_tracker, boundary_conditions) {
      self$frame_tracker <- frame_tracker
      self$boundary_conditions <- boundary_conditions
    },
    check_conditions = function() {
      current_frame <- self$frame_tracker$get_current_frame()
      for (condition in self$boundary_conditions) {
        if (!condition(current_frame)) {
          return(FALSE)
        }
      }
      return(TRUE)
    },
    handle_frame = function() {
      if (self$check_conditions()) {
        self$frame_tracker$update()
      }
    }
  )
)

SequenceHandler <- R6::R6Class("SequenceHandler",
  public = list(
    boundary_manager = NULL,
    initialize = function(boundary_manager) {
      self$boundary_manager <- boundary_manager
    },
    process = function() {
      while (TRUE) {
        self$boundary_manager$handle_frame()
      }
    }
  )
)

main <- function() {
  sequence <- c(1, 2, 3, 4, 5)
  boundary_conditions <- list(function(x) x > 0, function(x) x < 6)
  frame_tracker <- FrameTracker$new(sequence)
  boundary_manager <- BoundaryManager$new(frame_tracker, boundary_conditions)
  sequence_handler <- SequenceHandler$new(boundary_manager)
  sequence_handler$process()
}

main()