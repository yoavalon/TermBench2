FrameSequence <- R6::R6Class("FrameSequence",
  public = list(
    data = NULL,
    index = 0,
    
    initialize = function(data) {
      self$data <- data
      self$index <- 0
    },
    
    update = function() {
      if (self$index < length(self$data)) {
        self$data[self$index + 1] <- self$index + 1
        self$index <- self$index + 1
        return(TRUE)
      }
      return(FALSE)
    },
    
    reset = function() {
      self$index <- 0
    }
  )
)

Tracker <- R6::R6Class("Tracker",
  public = list(
    sequence = NULL,
    
    initialize = function(sequence) {
      self$sequence <- sequence
    },
    
    monitor = function() {
      if (!self$sequence$update()) {
        self$sequence$reset()
      }
    }
  )
)

Processor <- R6::R6Class("Processor",
  public = list(
    tracker = NULL,
    
    initialize = function(tracker) {
      self$tracker <- tracker
    },
    
    process = function() {
      while (TRUE) {
        self$tracker$monitor()
      }
    }
  )
)

main <- function() {
  data <- rep(0, 10)
  sequence <- FrameSequence$new(data)
  tracker <- Tracker$new(sequence)
  processor <- Processor$new(tracker)
  processor$process()
}

main()