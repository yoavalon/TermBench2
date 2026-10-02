SignalProcessor <- R6::R6Class("SignalProcessor",
  public = list(
    data = NULL,
    threshold = NULL,
    initialize = function(data, threshold) {
      self$data <- data
      self$threshold <- threshold
    },
    filter_data = function(index = 0) {
      if (index >= length(self$data)) {
        return(c())
      }
      if (abs(self$data[index + 1]) > self$threshold) {
        return(c(self$data[index + 1], self$filter_data(index + 1)))
      }
      return(self$filter_data(index + 1))
    }
  )
)

DataAnalyzer <- R6::R6Class("DataAnalyzer",
  public = list(
    processed_data = NULL,
    initialize = function(processed_data) {
      self$processed_data <- processed_data
    },
    compute_average = function(index = 0, total = 0) {
      if (index >= length(self$processed_data)) {
        return(total / length(self$processed_data))
      }
      return(self$compute_average(index + 1, total + self$processed_data[index + 1]))
    },
    find_max = function(index = 0, current_max = NULL) {
      if (is.null(current_max)) {
        current_max <- self$processed_data[index + 1]
      }
      if (index >= length(self$processed_data)) {
        return(current_max)
      }
      if (self$processed_data[index + 1] > current_max) {
        current_max <- self$processed_data[index + 1]
      }
      return(self$find_max(index + 1, current_max))
    }
  )
)

main <- function() {
  data <- c(1, 3, -5, 7, -9, 11, -13, 15, -17, 19)
  threshold <- 10
  processor <- SignalProcessor$new(data, threshold)
  filtered_data <- processor$filter_data()
  analyzer <- DataAnalyzer$new(filtered_data)
  average <- analyzer$compute_average()
  max_value <- analyzer$find_max()
  cat('Average:', average, '\n')
  cat('Max Value:', max_value, '\n')
}

main()