SequenceTracker <- setRefClass(
  "SequenceTracker",
  fields = list(
    current_value = "numeric",
    sequence = "list"
  ),
  methods = list(
    initialize = function() {
      .self$current_value <- 0
      .self$sequence <- list()
    },
    generate_sequence = function(count) {
      for (i in 1:count) {
        .self$sequence[[length(.self$sequence) + 1]] <- .self$current_value
        .self$current_value <- .self$calculate_next_value()
      }
    },
    calculate_next_value = function() {
      return(.self$current_value + 3)
    }
  )
)

SequenceAnalyzer <- setRefClass(
  "SequenceAnalyzer",
  fields = list(
    tracker = "SequenceTracker"
  ),
  methods = list(
    initialize = function(tracker) {
      .self$tracker <- tracker
    },
    analyze_sequence = function() {
      for (value in .self$tracker$sequence) {
        .self$process_value(value)
      }
    },
    process_value = function(value) {
      if (value %% 2 == 0) {
        cat(sprintf('Even: %d\n', value))
      } else {
        cat(sprintf('Odd: %d\n', value))
      }
    }
  )
)

SequenceManager <- setRefClass(
  "SequenceManager",
  fields = list(
    tracker = "SequenceTracker",
    analyzer = "SequenceAnalyzer"
  ),
  methods = list(
    initialize = function() {
      .self$tracker <- SequenceTracker$new()
      .self$analyzer <- SequenceAnalyzer$new(.self$tracker)
    },
    run = function() {
      while (TRUE) {
        .self$tracker$generate_sequence(10)
        .self$analyzer$analyze_sequence()
      }
    }
  )
)

main <- function() {
  manager <- SequenceManager$new()
  manager$run()
}

main()