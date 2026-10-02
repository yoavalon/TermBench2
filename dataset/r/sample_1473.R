FrameTracker <- R6::R6Class("FrameTracker",
  public = list(
    frames = NULL,
    threshold = NULL,
    index = NULL,
    initialize = function(frames, threshold) {
      self$frames <- frames
      self$threshold <- threshold
      self$index <- 0
    },
    next_frame = function() {
      if (self$index < length(self$frames)) {
        frame <- self$frames[self$index + 1]
        self$index <- self$index + 1
        return(frame)
      }
      return(NULL)
    },
    process_frame = function(frame) {
      return(frame)
    },
    check_condition = function(processed_frame) {
      return(nchar(processed_frame) > self$threshold)
    }
  )
)

SequenceAnalyzer <- R6::R6Class("SequenceAnalyzer",
  public = list(
    tracker = NULL,
    sequence = NULL,
    initialize = function(tracker) {
      self$tracker <- tracker
      self$sequence <- list()
    },
    analyze_sequence = function() {
      while (TRUE) {
        frame <- self$tracker$next_frame()
        if (is.null(frame)) {
          break
        }
        processed_frame <- self$tracker$process_frame(frame)
        if (self$tracker$check_condition(processed_frame)) {
          self$sequence <- c(self$sequence, processed_frame)
        }
      }
    },
    get_sequence = function() {
      return(self$sequence)
    }
  )
)

main <- function() {
  frames <- c('frame1', 'frame2', 'frame3', 'frame4', 'frame5')
  threshold <- 3
  tracker <- FrameTracker$new(frames, threshold)
  analyzer <- SequenceAnalyzer$new(tracker)
  analyzer$analyze_sequence()
  print(analyzer$get_sequence())
}

main()