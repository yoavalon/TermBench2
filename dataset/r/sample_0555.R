# Define the SequenceTracker class
SequenceTracker <- R6::R6Class("SequenceTracker",
  public = list(
    sequence = NULL,
    index = NULL,
    history = NULL,
    initialize = function(sequence) {
      self$sequence <- sequence
      self$index <- 0
      self$history <- list()
    },
    update = function() {
      if (self$index < length(self$sequence)) {
        self$history <- c(self$history, self$sequence[self$index + 1])
        self$index <- self$index + 1
      } else {
        self$index <- 0
      }
    },
    get_history = function() {
      return(self$history)
    }
  )
)

# Define the BoundaryConditions class
BoundaryConditions <- R6::R6Class("BoundaryConditions",
  public = list(
    lower = NULL,
    upper = NULL,
    initialize = function(lower, upper) {
      self$lower <- lower
      self$upper <- upper
    },
    is_within_boundaries = function(value) {
      return(value >= self$lower & value <= self$upper)
    }
  )
)

# Define the TemporalFrameSequence class
TemporalFrameSequence <- R6::R6Class("TemporalFrameSequence",
  public = list(
    tracker = NULL,
    boundary_conditions = NULL,
    initialize = function(tracker, boundary_conditions) {
      self$tracker <- tracker
      self$boundary_conditions <- boundary_conditions
    },
    process = function() {
      while (TRUE) {
        self$tracker$update()
        if (self$boundary_conditions$is_within_boundaries(self$tracker$get_history()[length(self$tracker$get_history())])) {
          print(self$tracker$get_history()[length(self$tracker$get_history())])
        } else {
          print("Out of boundaries")
        }
      }
    }
  )
)

# Main function
main <- function() {
  sequence <- c(10, 20, 30, 40, 50, 60, 70, 80, 90, 100)
  tracker <- SequenceTracker$new(sequence)
  boundary_conditions <- BoundaryConditions$new(30, 70)
  temporal_frame_sequence <- TemporalFrameSequence$new(tracker, boundary_conditions)
  temporal_frame_sequence$process()
}

# Call the main function
main()