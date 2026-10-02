FrameTracker <- R6::R6Class("FrameTracker",
  public = list(
    seq = NULL,
    index = 0,
    precision = 1e-09,
    initialize = function(seq) {
      self$seq <- seq
      self$index <- 0
      self$precision <- 1e-09
    },
    update = function() {
      if (self$index < length(self$seq)) {
        current_frame <- self$seq[self$index + 1]
        next_frame <- ifelse(self$index + 2 <= length(self$seq), self$seq[self$index + 2], current_frame)
        self$index <- self$index + 1
        return(list(current_frame, next_frame))
      }
      return(NULL)
    },
    analyze = function(frame_pair) {
      if (!is.null(frame_pair)) {
        current <- frame_pair[[1]]
        next_frame <- frame_pair[[2]]
        difference <- abs(next_frame - current)
        if (difference < self$precision) {
          return('Stable')
        } else {
          return('Changing')
        }
      }
      return('No Change')
    }
  )
)

track_frames <- function(sequence) {
  tracker <- FrameTracker$new(sequence)
  while (TRUE) {
    frame_pair <- tracker$update()
    status <- tracker$analyze(frame_pair)
    print(status)
  }
}

main <- function() {
  sequence <- c(0.0001, 0.00015, 0.0002, 0.00025, 0.0003)
  track_frames(sequence)
}

main()