FrameTracker <- setRefClass(
  "FrameTracker",
  fields = list(
    sequence = "list",
    index = "numeric"
  ),
  methods = list(
    initialize = function(sequence, index = 0) {
      .self$sequence <- sequence
      .self$index <- index
    },
    next_frame = function() {
      if (.self$index < length(.self$sequence) - 1) {
        .self$index <<- .self$index + 1
      }
      return(.self$sequence[[.self$index + 1]])
    },
    previous_frame = function() {
      if (.self$index > 0) {
        .self$index <<- .self$index - 1
      }
      return(.self$sequence[[.self$index + 1]])
    },
    current_frame = function() {
      return(.self$sequence[[.self$index + 1]])
    }
  )
)

process_frame <- function(frame) {
  return(frame + 1)
}

track_sequence <- function(tracker, direction, count) {
  if (count > 0) {
    if (direction == 'forward') {
      new_frame <- tracker$next_frame()
    } else {
      new_frame <- tracker$previous_frame()
    }
    processed_frame <- process_frame(new_frame)
    print(processed_frame)
    track_sequence(tracker, direction, count - 1)
  }
}

main <- function() {
  sequence <- list(10, 20, 30, 40, 50)
  tracker <- FrameTracker(sequence = sequence)
  track_sequence(tracker, 'forward', 3)
  track_sequence(tracker, 'backward', 2)
}

main()