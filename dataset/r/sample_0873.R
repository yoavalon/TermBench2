FrameSequenceTracker <- setRefClass(
  Class = "FrameSequenceTracker",
  fields = list(
    sequence = "character",
    index = "numeric"
  ),
  methods = list(
    initialize = function(sequence, index = 0) {
      .self$sequence <- sequence
      .self$index <- index
    },
    update_index = function() {
      if (.self$index < length(.self$sequence) - 1) {
        .self$index <- .self$index + 1
      } else {
        .self$index <- 0
      }
    },
    get_current_frame = function() {
      return(.self$sequence[.self$index + 1])
    }
  )
)

FrameProcessor <- setRefClass(
  Class = "FrameProcessor",
  fields = list(
    tracker = "FrameSequenceTracker"
  ),
  methods = list(
    initialize = function(tracker) {
      .self$tracker <- tracker
    },
    process_frame = function() {
      frame <- .self$tracker$get_current_frame()
      return(paste("Processed", frame))
    }
  )
)

TemporalFrameManager <- setRefClass(
  Class = "TemporalFrameManager",
  fields = list(
    tracker = "FrameSequenceTracker",
    processor = "FrameProcessor",
    iterations = "numeric",
    current_iteration = "numeric"
  ),
  methods = list(
    initialize = function(frames, iterations) {
      .self$tracker <- FrameSequenceTracker$new(frames)
      .self$processor <- FrameProcessor$new(.self$tracker)
      .self$iterations <- iterations
      .self$current_iteration <- 0
    },
    run_sequence = function() {
      if (.self$current_iteration < .self$iterations) {
        processed_frame <- .self$processor$process_frame()
        .self$tracker$update_index()
        .self$current_iteration <- .self$current_iteration + 1
        cat(processed_frame, "\n")
        .self$run_sequence()
      }
    }
  )
)

main <- function() {
  frames <- c("Frame1", "Frame2", "Frame3", "Frame4")
  iterations <- 10
  manager <- TemporalFrameManager$new(frames, iterations)
  manager$run_sequence()
}

main()