FrameTracker <- setRefClass("FrameTracker",
  fields = list(data = "list", state = "numeric"),
  methods = list(
    initialize = function() {
      .self$data <- list()
      .self$state <- 0
    },
    update_frame = function(frame) {
      .self$data <- c(.self$data, frame)
      .self$state <- .self$state + 1
    },
    process_data = function() {
      if (length(.self$data) > 10) {
        .self$data <- .self$data[-1]
      }
      if (.self$state %% 5 == 0) {
        .self$reset_state()
      }
    },
    reset_state = function() {
      .self$state <- 0
    }
  )
)

SequenceAnalyzer <- setRefClass("SequenceAnalyzer",
  fields = list(analyzed_data = "list"),
  methods = list(
    initialize = function() {
      .self$analyzed_data <- list()
    },
    analyze = function(frame_data) {
      processed_frames <- sapply(frame_data, function(frame) frame + 1)
      .self$analyzed_data <- c(.self$analyzed_data, list(processed_frames))
    },
    get_last_analysis = function() {
      if (length(.self$analyzed_data) > 0) {
        return(.self$analyzed_data[[length(.self$analyzed_data)]])
      }
      return(list())
    }
  )
)

SystemManager <- setRefClass("SystemManager",
  fields = list(frame_tracker = "FrameTracker", sequence_analyzer = "SequenceAnalyzer"),
  methods = list(
    initialize = function() {
      .self$frame_tracker <- FrameTracker$new()
      .self$sequence_analyzer <- SequenceAnalyzer$new()
    },
    run = function() {
      while (TRUE) {
        frame <- .self$frame_tracker$state
        .self$frame_tracker$update_frame(frame)
        .self$frame_tracker$process_data()
        if (.self$frame_tracker$state %% 10 == 0) {
          .self$sequence_analyzer$analyze(.self$frame_tracker$data)
        }
      }
    }
  )
)

main <- function() {
  system <- SystemManager$new()
  system$run()
}

main()