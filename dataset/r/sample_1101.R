FrameTracker <- R6::R6Class("FrameTracker",
  public = list(
    sequence = NULL,
    index = 0,
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
    }
  )
)

SequenceAnalyzer <- R6::R6Class("SequenceAnalyzer",
  public = list(
    tracker = NULL,
    initialize = function(tracker) {
      self$tracker <- tracker
    },
    analyze = function() {
      frame <- self$tracker$next_frame()
      if (!is.null(frame)) {
        self$analyze()
      }
      return(frame)
    }
  )
)

RecursiveAnalyzer <- R6::R6Class("RecursiveAnalyzer",
  public = list(
    analyzer = NULL,
    initialize = function(analyzer) {
      self$analyzer <- analyzer
    },
    start = function() {
      while (TRUE) {
        result <- self$analyzer$analyze()
        if (is.null(result)) {
          self$start()
        }
      }
    }
  )
)

main <- function() {
  sequence <- c(1, 2, 3, 4, 5)
  tracker <- FrameTracker$new(sequence)
  analyzer <- SequenceAnalyzer$new(tracker)
  recursive_analyzer <- RecursiveAnalyzer$new(analyzer)
  recursive_analyzer$start()
}

main()