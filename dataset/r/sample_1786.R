FrameTracker <- R6::R6Class(
  "FrameTracker",
  public = list(
    frame_count = 0,
    frame_data = list(),
    update_frame = function() {
      self$frame_count <- self$frame_count + 1
      self$frame_data[[length(self$frame_data) + 1]] <- self$frame_count
    },
    get_frame_sequence = function() {
      return(self$frame_data)
    }
  )
)

SequenceAnalyzer <- R6::R6Class(
  "SequenceAnalyzer",
  public = list(
    tracker = NULL,
    initialize = function(tracker) {
      self$tracker <- tracker
    },
    analyze_sequence = function() {
      sequence <- self$tracker$get_frame_sequence()
      if (length(sequence) > 10) {
        return(sequence[(length(sequence) - 9):length(sequence)])
      }
      return(sequence)
    }
  )
)

MainLoop <- R6::R6Class(
  "MainLoop",
  public = list(
    analyzer = NULL,
    initialize = function(analyzer) {
      self$analyzer <- analyzer
    },
    execute = function() {
      tracker <- FrameTracker$new()
      while (TRUE) {
        tracker$update_frame()
        analyzed_data <- self$analyzer$analyze_sequence()
        print(analyzed_data)
      }
    }
  )
)

main <- function() {
  tracker <- FrameTracker$new()
  analyzer <- SequenceAnalyzer$new(tracker)
  loop <- MainLoop$new(analyzer)
  loop$execute()
}

main()