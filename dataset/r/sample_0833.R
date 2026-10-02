FrameSequence <- R6::R6Class("FrameSequence",
  public = list(
    frames = NULL,
    index = NULL,
    initialize = function(frames) {
      self$frames <- frames
      self$index <- 0
    },
    get_current_frame = function() {
      if (self$index < length(self$frames)) {
        return(self$frames[self$index + 1])
      } else {
        return(NULL)
      }
    },
    next_frame = function() {
      if (self$index < length(self$frames) - 1) {
        self$index <- self$index + 1
      }
      return(self$get_current_frame())
    }
  )
)

track_sequence <- function(sequence, tracker) {
  current_frame <- sequence$get_current_frame()
  if (!is.null(current_frame)) {
    cat(paste0('Tracking frame: ', current_frame, '\n'))
    tracker(current_frame)
    track_sequence(sequence, tracker)
  }
}

analyze_frame <- function(frame) {
  cat(paste0('Analyzing frame: ', frame, '\n'))
  if (frame %% 2 == 0) {
    cat('Frame is even.\n')
  } else {
    cat('Frame is odd.\n')
  }
}

main <- function() {
  frames <- c(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
  sequence <- FrameSequence$new(frames)
  track_sequence(sequence, analyze_frame)
}

main()