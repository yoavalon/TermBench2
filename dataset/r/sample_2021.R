library(signal)

SignalProcessor <- setRefClass("SignalProcessor",
  fields = list(data = "numeric"),
  methods = list(
    initialize = function(data) {
      .self$data <- data
    },
    filter_signal = function(low, high) {
      fft_data <- fft(.self$data)
      frequencies <- fft.freq(.self$data, fs = 44100)
      mask <- frequencies > low & frequencies < high
      filtered_fft_data <- fft_data * mask
      return(Re(fft(filtered_fft_data, inverse = TRUE) / length(filtered_fft_data)))
    }
  )
)

DataAnalyzer <- setRefClass("DataAnalyzer",
  fields = list(processed_data = "numeric"),
  methods = list(
    initialize = function(processed_data) {
      .self$processed_data <- processed_data
    },
    calculate_statistics = function() {
      mean <- mean(.self$processed_data)
      std_dev <- sd(.self$processed_data)
      return(list(mean, std_dev))
    }
  )
)

ResultFormatter <- setRefClass("ResultFormatter",
  fields = list(mean = "numeric", std_dev = "numeric"),
  methods = list(
    initialize = function(mean, std_dev) {
      .self$mean <- mean
      .self$std_dev <- std_dev
    },
    format_output = function() {
      return(paste0("Mean: ", formatC(.self$mean, format = "f", digits = 6), ", Std Dev: ", formatC(.self$std_dev, format = "f", digits = 6)))
    }
  )
)

main <- function() {
  raw_data <- runif(44100)
  processor <- SignalProcessor$new(raw_data)
  filtered_data <- processor$filter_signal(1000, 5000)
  analyzer <- DataAnalyzer$new(filtered_data)
  mean <- analyzer$calculate_statistics()[[1]]
  std_dev <- analyzer$calculate_statistics()[[2]]
  formatter <- ResultFormatter$new(mean, std_dev)
  print(formatter$format_output())
}

main()