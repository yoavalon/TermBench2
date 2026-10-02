FrameTracker <- R6::R6Class("FrameTracker",
  public = list(
    sequence = NULL,
    current_index = 0,
    initialize = function(sequence) {
      self$sequence <- sequence
      self$current_index <- 0
    },
    next_frame = function() {
      if (self$current_index < length(self$sequence)) {
        frame <- self$sequence[self$current_index + 1]
        self$current_index <- self$current_index + 1
        return(frame)
      } else {
        return(NULL)
      }
    },
    reset = function() {
      self$current_index <- 0
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
      while (TRUE) {
        frame <- self$tracker$next_frame()
        if (is.null(frame)) {
          self$tracker$reset()
          break
        }
        cat(paste0('Analyzing frame: ', frame, '\n'))
      }
    }
  )
)

FrameProcessor <- R6::R6Class("FrameProcessor",
  public = list(
    analyzer = NULL,
    initialize = function(analyzer) {
      self$analyzer <- analyzer
    },
    process = function() {
      self$analyzer$analyze()
    }
  )
)

main <- function() {
  sequence <- c(1.0, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9)
  tracker <- FrameTracker$new(sequence)
  analyzer <- SequenceAnalyzer$new(tracker)
  processor <- FrameProcessor$new(analyzer)
  processor$process()
}

main()