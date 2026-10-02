library(rlang)

TemporalFrameSequence <- R6::R6Class("TemporalFrameSequence",
  public = list(
    sequence = NULL,
    threshold = NULL,
    initialize = function(sequence, threshold) {
      self$sequence <- sequence
      self$threshold <- threshold
    },
    calculate_precision = function() {
      precision <- sapply(self$sequence, function(frame) {
        max(signif(frame, 22) - frame)
      })
      return(precision)
    },
    filter_by_threshold = function(precision) {
      filtered_sequence <- self$sequence[precision > self$threshold]
      return(filtered_sequence)
    }
  )
)

PrecisionAnalyzer <- R6::R6Class("PrecisionAnalyzer",
  public = list(
    data = NULL,
    initialize = function(data) {
      self$data <- data
    },
    analyze = function() {
      total_precision <- sum(self$data)
      average_precision <- ifelse(length(self$data) > 0, total_precision / length(self$data), 0)
      return(average_precision)
    }
  )
)

main <- function() {
  sequence <- c(1.0, 2.0, 3.0, 4.0, 5.0)
  threshold <- 23
  temporal_frame <- TemporalFrameSequence$new(sequence, threshold)
  precision <- temporal_frame$calculate_precision()
  filtered_sequence <- temporal_frame$filter_by_threshold(precision)
  analyzer <- PrecisionAnalyzer$new(precision)
  average_precision <- analyzer$analyze()
  print(average_precision)
}

main()