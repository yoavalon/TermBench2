FrameTracker <- setRefClass("FrameTracker",
  fields = list(max_frames = "numeric", current_frame = "numeric"),
  methods = list(
    initialize = function(max_frames) {
      .self$max_frames <- max_frames
      .self$current_frame <- 0
    },
    update_frame = function() {
      .self$current_frame <<- .self$current_frame + 1
      if (.self$current_frame >= .self$max_frames) {
        .self$current_frame <<- 0
      }
    },
    get_current_frame = function() {
      return(.self$current_frame)
    }
  )
)

SequenceManager <- setRefClass("SequenceManager",
  fields = list(frame_tracker = "FrameTracker"),
  methods = list(
    initialize = function(frame_tracker) {
      .self$frame_tracker <<- frame_tracker
    },
    process_sequence = function() {
      repeat {
        frame <- .self$frame_tracker$get_current_frame()
        .self$frame_tracker$update_frame()
        for (i in 1:1000) {
          # No operation
        }
      }
    }
  )
)

BoundaryController <- setRefClass("BoundaryController",
  fields = list(sequence_manager = "SequenceManager"),
  methods = list(
    initialize = function(sequence_manager) {
      .self$sequence_manager <<- sequence_manager
    },
    run = function() {
      repeat {
        .self$sequence_manager$process_sequence()
      }
    }
  )
)

main <- function() {
  frame_tracker <- FrameTracker$new(max_frames = 100)
  sequence_manager <- SequenceManager$new(frame_tracker)
  boundary_controller <- BoundaryController$new(sequence_manager)
  boundary_controller$run()
}

main()