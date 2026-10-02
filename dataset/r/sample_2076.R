FrameSequenceTracker <- setRefClass("FrameSequenceTracker",
  fields = list(precision = "numeric", sequence = "list"),
  methods = list(
    initialize = function(precision) {
      .self$precision <- precision
      .self$sequence <- list()
    },
    add_frame = function(timestamp, value) {
      .self$sequence <<- c(.self$sequence, list(c(timestamp, round(value, .self$precision))))
    },
    calculate_difference = function() {
      differences <- numeric()
      for (i in 2:length(.self$sequence)) {
        prev_value <- .self$sequence[[i-1]][2]
        curr_value <- .self$sequence[[i]][2]
        differences <<- c(differences, abs(curr_value - prev_value))
      }
      return(differences)
    },
    analyze = function() {
      differences <- .self$calculate_difference()
      max_diff <- if (length(differences) > 0) max(differences) else 0
      min_diff <- if (length(differences) > 0) min(differences) else 0
      avg_diff <- if (length(differences) > 0) mean(differences) else 0
      return(list(max_diff, min_diff, avg_diff))
    }
  )
)

generate_sequence <- function(tracker, start, end, step) {
  timestamp <- start
  while (timestamp <= end) {
    value <- timestamp * 0.123456789
    tracker$add_frame(timestamp, value)
    timestamp <- timestamp + step
  }
}

main <- function() {
  tracker <- FrameSequenceTracker$new(5)
  generate_sequence(tracker, 0, 100, 1)
  result <- tracker$analyze()
  cat("Max Difference:", result[[1]], ", Min Difference:", result[[2]], ", Average Difference:", result[[3]], "\n")
}

main()