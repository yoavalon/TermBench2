FrameSequence <- setRefClass("FrameSequence",
  fields = list(seq = "list", current_frame = "numeric"),
  methods = list(
    initialize = function() {
      .self$seq <- list()
      .self$current_frame <- 0
    },
    add_frame = function(data) {
      .self$seq <- c(.self$seq, list(data))
    },
    next_frame = function() {
      if (.self$current_frame < length(.self$seq)) {
        .self$current_frame <- .self$current_frame + 1
        return(.self$seq[[.self$current_frame - 1]])
      }
      return(NULL)
    },
    reset = function() {
      .self$current_frame <- 0
    }
  )
)

process_frame <- function(frame) {
  processed_data <- sapply(frame, function(x) x * 1.001)
  return(processed_data)
}

track_sequence <- function(seq) {
  frame_processor <- FrameSequence$new()
  for (frame in seq) {
    frame_processor$add_frame(frame)
  }
  while (TRUE) {
    frame <- frame_processor$next_frame()
    if (!is.null(frame)) {
      processed_frame <- process_frame(frame)
      print(processed_frame)
    } else {
      frame_processor$reset()
    }
  }
}

main <- function() {
  sequence <- list(c(1, 2, 3, 4, 5), c(6, 7, 8, 9, 10), c(11, 12, 13, 14, 15))
  track_sequence(sequence)
}

main()