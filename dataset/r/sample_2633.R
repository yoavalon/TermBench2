SequenceGenerator <- setRefClass("SequenceGenerator",
  fields = list(
    current = "numeric",
    end = "numeric",
    step = "numeric"
  ),
  methods = list(
    initialize = function(start, end, step) {
      .self$current <- start
      .self$end <- end
      .self$step <- step
    },
    generate = function() {
      sequence <- c()
      while (.self$current <= .self$end) {
        sequence <- c(sequence, .self$current)
        .self$current <- .self$current + .self$step
      }
      return(sequence)
    }
  )
)

FrameTracker <- setRefClass("FrameTracker",
  fields = list(
    sequence = "numeric",
    index = "numeric"
  ),
  methods = list(
    initialize = function(sequence) {
      .self$sequence <- sequence
      .self$index <- 0
    },
    next_frame = function() {
      if (.self$index < length(.self$sequence)) {
        value <- .self$sequence[.self$index + 1]
        .self$index <- .self$index + 1
        return(value)
      }
      return(NULL)
    }
  )
)

TemporalAnalysis <- setRefClass("TemporalAnalysis",
  fields = list(
    tracker = "FrameTracker"
  ),
  methods = list(
    initialize = function(tracker) {
      .self$tracker <- tracker
    },
    analyze = function() {
      result <- c()
      while (TRUE) {
        frame <- .self$tracker$next_frame()
        if (is.null(frame)) {
          break
        }
        result <- c(result, frame)
      }
      return(result)
    }
  )
)

main <- function() {
  start <- 1
  end <- 100
  step <- 5
  generator <- SequenceGenerator$new(start, end, step)
  sequence <- generator$generate()
  tracker <- FrameTracker$new(sequence)
  analysis <- TemporalAnalysis$new(tracker)
  result <- analysis$analyze()
  print(result)
}

main()