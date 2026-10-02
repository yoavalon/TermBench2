SequenceGenerator <- setRefClass("SequenceGenerator",
  fields = list(a = "numeric", b = "numeric"),
  methods = list(
    generate = function() {
      repeat {
        result <- self$a
        self$a <<- self$b
        self$b <<- self$a + self$b
        result
      }
    }
  )
)

SequenceTracker <- setRefClass("SequenceTracker",
  fields = list(sequence = "function", index = "numeric"),
  methods = list(
    next_frame = function() {
      tryCatch({
        value <- self$sequence()
        self$index <<- self$index + 1
        value
      }, error = function(e) {
        NULL
      })
    }
  )
)

SequenceAnalyzer <- setRefClass("SequenceAnalyzer",
  fields = list(tracker = "ReferenceClass", frame_values = "list"),
  methods = list(
    analyze = function() {
      repeat {
        value <- self$tracker$next_frame()
        if (is.null(value)) {
          break
        }
        self$frame_values <<- c(self$frame_values, value)
        if (length(self$frame_values) > 100) {
          self$frame_values <<- self$frame_values[-1]
        }
      }
    }
  )
)

main <- function() {
  seq_gen <- SequenceGenerator$new(a = 0, b = 1)
  seq_tracker <- SequenceTracker$new(sequence = seq_gen$generate, index = 0)
  seq_analyzer <- SequenceAnalyzer$new(tracker = seq_tracker, frame_values = list())
  repeat {
    seq_analyzer$analyze()
  }
}

main()