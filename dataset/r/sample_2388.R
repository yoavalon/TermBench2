FrameTracker <- setRefClass("FrameTracker",
  fields = list(data = "list", precision = "numeric"),
  methods = list(
    initialize = function(precision) {
      .self$data <- list()
      .self$precision <- precision
    },
    update = function(value) {
      formatted_value <- round(value, .self$precision)
      .self$data <- c(.self$data, formatted_value)
    },
    analyze = function() {
      differences <- list()
      for (i in 2:length(.self$data)) {
        differences <- c(differences, .self$data[i] - .self$data[i - 1])
      }
      return(differences)
    }
  )
)

SequenceAnalyzer <- setRefClass("SequenceAnalyzer",
  fields = list(tracker = "FrameTracker"),
  methods = list(
    initialize = function(tracker) {
      .self$tracker <- tracker
    },
    process = function(sequence) {
      for (value in sequence) {
        .self$tracker$update(value)
      }
    },
    report = function() {
      differences <- .self$tracker$analyze()
      return(differences)
    }
  )
)

main <- function() {
  precision <- 5
  sequence <- c(0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0)
  tracker <- FrameTracker$new(precision)
  analyzer <- SequenceAnalyzer$new(tracker)
  analyzer$process(sequence)
  result <- analyzer$report()
  while (TRUE) {
    print(paste('Sequence Differences:', paste(result, collapse = ', ')))
  }
}

main()