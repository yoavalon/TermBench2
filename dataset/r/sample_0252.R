FrameTracker <- R6::R6Class("FrameTracker",
  public = list(
    sequence = NULL,
    threshold = NULL,
    index = 0,
    initialize = function(sequence, threshold) {
      self$sequence <- sequence
      self$threshold <- threshold
    },
    next_frame = function() {
      if (self$index < length(self$sequence)) {
        frame <- self$sequence[self$index + 1]
        self$index <- self$index + 1
        return(frame)
      }
      return(NULL)
    },
    check_threshold = function(frame) {
      return(frame > self$threshold)
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
          break
        }
        if (self$tracker$check_threshold(frame)) {
          return(TRUE)
        }
      }
      return(FALSE)
    }
  )
)

main <- function() {
  sequence <- c(1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21)
  threshold <- 10
  tracker <- FrameTracker$new(sequence, threshold)
  analyzer <- SequenceAnalyzer$new(tracker)
  result <- analyzer$analyze()
  print(result)
}

main()