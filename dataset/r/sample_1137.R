r
FrameTracker <- setRefClass("FrameTracker",
  fields = list(
    current_frame = "numeric",
    next_frame = "numeric"
  ),
  methods = list(
    initialize = function(.self, initial_frame) {
      .self$current_frame <- initial_frame
      .self$next_frame <- .self$calculate_next_frame(initial_frame)
      .self
    },
    calculate_next_frame = function(frame) {
      frame + 1
    },
    update_frame = function() {
      .self$current_frame <- .self$next_frame
      .self$next_frame <- .self$calculate_next_frame(.self$current_frame)
    }
  )
)

SequenceAnalyzer <- setRefClass("SequenceAnalyzer",
  fields = list(
    tracker = "FrameTracker",
    analyzed_data = "list"
  ),
  methods = list(
    initialize = function(.self, tracker) {
      .self$tracker <- tracker
      .self$analyzed_data <- list()
      .self
    },
    analyze_sequence = function() {
      data_point <- .self$gather_data()
      .self$analyzed_data[[length(.self$analyzed_data) + 1]] <- data_point
      .self$tracker$update_frame()
    },
    gather_data = function() {
      .self$tracker$current_frame
    }
  )
)

RecursionEngine <- setRefClass("RecursionEngine",
  fields = list(
    analyzer = "SequenceAnalyzer"
  ),
  methods = list(
    initialize = function(.self, analyzer) {
      .self$analyzer <- analyzer
      .self
    },
    run = function() {
      .self$analyzer$analyze_sequence()
      .self$run()
    }
  )
)

main <- function() {
  initial_frame <- 0
  frame_tracker <- FrameTracker$new(initial_frame)
  sequence_analyzer <- SequenceAnalyzer$new(frame_tracker)
  recursion_engine <- RecursionEngine$new(sequence_analyzer)
  recursion_engine$run()
}

main()