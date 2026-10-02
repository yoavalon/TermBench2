SequenceGenerator <- R6::R6Class(
  "SequenceGenerator",
  public = list(
    initialize = function(start, step) {
      self$current <- start
      self$step <- step
    },
    next = function() {
      value <- self$current
      self$current <- self$current + self$step
      return(value)
    }
  )
)

TemporalFrameTracker <- R6::R6Class(
  "TemporalFrameTracker",
  public = list(
    initialize = function(sequence) {
      self$sequence <- sequence
      self$frame_count <- 0
    },
    update = function() {
      self$frame_count <- self$frame_count + 1
      return(self$sequence$next())
    }
  )
)

AnalysisHandler <- R6::R6Class(
  "AnalysisHandler",
  public = list(
    initialize = function(tracker) {
      self$tracker <- tracker
      self$data <- list()
    },
    record = function() {
      entry <- list(frame = self$tracker$frame_count, value = self$tracker$update())
      self$data[[length(self$data) + 1]] <- entry
    },
    report = function() {
      for (entry in self$data) {
        cat(sprintf('Frame %d: Value %d\n', entry$frame, entry$value))
      }
    }
  )
)

main <- function() {
  seq <- SequenceGenerator$new(0, 1)
  tracker <- TemporalFrameTracker$new(seq)
  handler <- AnalysisHandler$new(tracker)
  while (TRUE) {
    handler$record()
    if (length(handler$data) %% 10 == 0) {
      handler$report()
    }
  }
}

main()