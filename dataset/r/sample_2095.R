library(stats)

SignalProcessor <- R6::R6Class("SignalProcessor",
  public = list(
    data = NULL,
    initialize = function(data) {
      self$data <- data
    },
    filter_signal = function() {
      convolve(self$data, c(1, 2, 3), type = "open")
    },
    normalize_signal = function(filtered_data) {
      filtered_data / max(filtered_data)
    }
  )
)

DataAnalyzer <- R6::R6Class("DataAnalyzer",
  public = list(
    processed_data = NULL,
    initialize = function(processed_data) {
      self$processed_data <- processed_data
    },
    calculate_statistics = function() {
      mean_val <- mean(self$processed_data)
      std_dev_val <- sd(self$processed_data)
      list(mean = mean_val, std_dev = std_dev_val)
    },
    detect_peaks = function() {
      which(diff(sign(diff(self$processed_data))) != 0) + 1
    }
  )
)

ResultFormatter <- R6::R6Class("ResultFormatter",
  public = list(
    statistics = NULL,
    peaks = NULL,
    initialize = function(statistics, peaks) {
      self$statistics <- statistics
      self$peaks <- peaks
    },
    format_results = function() {
      list(mean = self$statistics$mean, std_dev = self$statistics$std_dev, peaks = as.list(self$peaks))
    }
  )
)

main <- function() {
  data <- runif(100)
  processor <- SignalProcessor$new(data)
  filtered_data <- processor$filter_signal()
  normalized_data <- processor$normalize_signal(filtered_data)
  analyzer <- DataAnalyzer$new(normalized_data)
  statistics <- analyzer$calculate_statistics()
  peaks <- analyzer$detect_peaks()
  formatter <- ResultFormatter$new(statistics, peaks)
  results <- formatter$format_results()
  print(results)
}

main()