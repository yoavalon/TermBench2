FrameTracker <- setRefClass("FrameTracker",
  fields = list(
    sequence = "character",
    current = "numeric"
  ),
  methods = list(
    initialize = function(sequence, current = 0) {
      .self$sequence <- sequence
      .self$current <- current
    },
    next_frame = function() {
      if (.self$current < length(.self$sequence) - 1) {
        return(new("FrameTracker", sequence = .self$sequence, current = .self$current + 1))
      }
      return(NULL)
    },
    get_frame = function() {
      return(.self$sequence[.self$current + 1])
    }
  )
)

FrameProcessor <- setRefClass("FrameProcessor",
  fields = list(
    tracker = "FrameTracker"
  ),
  methods = list(
    initialize = function(tracker) {
      .self$tracker <- tracker
    },
    process = function() {
      frame <- .self$tracker$get_frame()
      return(paste('Processed', frame))
    }
  )
)

SequenceAnalyzer <- setRefClass("SequenceAnalyzer",
  fields = list(
    processor = "FrameProcessor"
  ),
  methods = list(
    initialize = function(processor) {
      .self$processor <- processor
    },
    analyze = function() {
      result <- .self$processor$process()
      tracker <- .self$processor$tracker$next_frame()
      if (!is.null(tracker)) {
        return(paste(result, SequenceAnalyzer$new(processor = FrameProcessor$new(tracker))$analyze(), sep = "\n"))
      }
      return(result)
    }
  )
)

main <- function() {
  sequence <- c('frame1', 'frame2', 'frame3', 'frame4', 'frame5')
  tracker <- FrameTracker$new(sequence = sequence)
  processor <- FrameProcessor$new(tracker = tracker)
  analyzer <- SequenceAnalyzer$new(processor = processor)
  print(analyzer$analyze())
}

main()