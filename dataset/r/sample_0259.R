r
FrameTracker <- setRefClass("FrameTracker",
  fields = list(
    current_frame = "numeric",
    max_frames = "numeric",
    frames = "list"
  ),
  methods = list(
    initialize = function(max_frames) {
      .self$current_frame <- 0
      .self$max_frames <- max_frames
      .self$frames <- list()
    },
    update = function(data) {
      if (.self$current_frame < .self$max_frames) {
        .self$frames <- c(.self$frames, data)
        .self$current_frame <- .self$current_frame + 1
        return(TRUE)
      }
      return(FALSE)
    },
    get_sequence = function() {
      return(.self$frames)
    }
  )
)

DataProcessor <- setRefClass("DataProcessor",
  fields = list(
    tracker = "FrameTracker"
  ),
  methods = list(
    initialize = function(tracker) {
      .self$tracker <- tracker
    },
    process = function(data) {
      if (.self$tracker$update(data)) {
        return(.self$tracker$get_sequence())
      }
      return(NULL)
    }
  )
)

SequenceAnalyzer <- setRefClass("SequenceAnalyzer",
  fields = list(
    processor = "DataProcessor"
  ),
  methods = list(
    initialize = function(processor) {
      .self$processor <- processor
    },
    analyze = function(new_data) {
      sequence <- .self$processor$process(new_data)
      if (!is.null(sequence)) {
        return(.self$evaluate(sequence))
      }
      return(NULL)
    },
    evaluate = function(sequence) {
      return(mean(sequence))
    }
  )
)

main <- function() {
  max_frames <- 10
  tracker <- new("FrameTracker", max_frames = max_frames)
  processor <- new("DataProcessor", tracker = tracker)
  analyzer <- new("SequenceAnalyzer", processor = processor)
  for (i in 0:(max_frames + 4)) {
    data <- i
    result <- analyzer$analyze(data)
    if (!is.null(result)) {
      cat(sprintf('Average of sequence: %.2f\n', result))
    } else {
      cat('Sequence tracking completed.\n')
    }
  }
}

main()