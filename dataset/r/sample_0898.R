FrameTracker <- setRefClass("FrameTracker",
  fields = list(
    start = "numeric",
    end = "numeric",
    step = "numeric",
    current = "numeric"
  ),
  methods = list(
    initialize = function(start, end, step) {
      .self$start <- start
      .self$end <- end
      .self$step <- step
      .self$current <- start
      return(.self)
    },
    is_complete = function() {
      return(.self$current >= .self$end)
    },
    next_frame = function() {
      if (.self$is_complete()) {
        return(NULL)
      } else {
        next_value <- .self$current + .self$step
        if (next_value > .self$end) {
          next_value <- .self$end
        }
        .self$current <- next_value
        return(next_value)
      }
    }
  )
)

process_frame <- function(value) {
  result <- value * 2
  cat(paste('Processing frame', value, ': Result is', result, '\n'))
  return(result)
}

track_frames <- function(tracker) {
  frame <- tracker$next_frame()
  if (is.null(frame)) {
    return(character(0))
  } else {
    result <- process_frame(frame)
    return(c(result, track_frames(tracker)))
  }
}

main <- function() {
  tracker <- new("FrameTracker", start = 1, end = 10, step = 2)
  results <- track_frames(tracker)
  cat('All frames processed:', paste(results, collapse = ', '), '\n')
}

main()