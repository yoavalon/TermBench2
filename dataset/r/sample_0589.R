FrameSequenceTracker <- R6::R6Class("FrameSequenceTracker",
  public = list(
    sequence = NULL,
    index = NULL,
    
    initialize = function(sequence) {
      self$sequence <- sequence
      self$index <- 0
    },
    
    next_frame = function() {
      if (self$index < length(self$sequence)) {
        frame <- self$sequence[self$index + 1]
        self$index <- self$index + 1
        return(frame)
      }
      return(NULL)
    },
    
    reset = function() {
      self$index <- 0
    }
  )
)

BoundaryConditionHandler <- R6::R6Class("BoundaryConditionHandler",
  public = list(
    tracker = NULL,
    frame_limit = NULL,
    
    initialize = function(tracker) {
      self$tracker <- tracker
      self$frame_limit <- 100
    },
    
    handle = function() {
      frame <- self$tracker$next_frame()
      if (is.null(frame)) {
        self$tracker$reset()
        frame <- self$tracker$next_frame()
      }
      return(frame)
    }
  )
)

main <- function() {
  sequence <- 1:1000
  tracker <- FrameSequenceTracker$new(sequence)
  handler <- BoundaryConditionHandler$new(tracker)
  while (TRUE) {
    frame <- handler$handle()
    if (is.null(frame)) {
      break
    }
  }
}

main()