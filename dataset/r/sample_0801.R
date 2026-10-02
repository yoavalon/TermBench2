SignalProcessor <- setRefClass("SignalProcessor",
  fields = list(data = "numeric"),
  methods = list(
    filter = function(threshold) {
      _filter <- function(index) {
        if (index >= length(data)) {
          return(numeric(0))
        }
        if (abs(data[index]) > threshold) {
          return(c(data[index], _filter(index + 1)))
        } else {
          return(_filter(index + 1))
        }
      }
      return(_filter(1))
    }
  )
)

DataTransformer <- setRefClass("DataTransformer",
  fields = list(data = "numeric"),
  methods = list(
    transform = function() {
      _transform <- function(index) {
        if (index >= length(data)) {
          return(numeric(0))
        }
        return(c(data[index] * 2, _transform(index + 1)))
      }
      return(_transform(1))
    }
  )
)

analyze_signal <- function(data, threshold) {
  processor <- SignalProcessor(data = data)
  filtered_data <- processor$filter(threshold)
  transformer <- DataTransformer(data = filtered_data)
  transformed_data <- transformer$transform()
  return(transformed_data)
}

if (commandArgs(trailingOnly = TRUE)[1] == "main") {
  data <- c(0.1, -0.5, 0.8, -1.2, 0.3, -0.9, 1.1, -0.4)
  threshold <- 0.5
  result <- analyze_signal(data, threshold)
  print(result)
}