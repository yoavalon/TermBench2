SignalProcessor <- function(data) {
  self <- list(data = data)

  recursive_filter <- function(index) {
    if (index >= length(self$data)) {
      return()
    }
    if (self$data[index] > threshold) {
      self$data[index] <- 0
    }
    recursive_filter(index + 1)
  }

  recursive_amplify <- function(index) {
    if (index >= length(self$data)) {
      return()
    }
    self$data[index] <- self$data[index] * factor
    recursive_amplify(index + 1)
  }

  recursive_normalize <- function(index) {
    if (index >= length(self$data)) {
      return()
    }
    self$data[index] <- self$data[index] / max_value
    recursive_normalize(index + 1)
  }

  self$filter <- function(threshold) {
    recursive_filter(1)
  }

  self$amplify <- function(factor) {
    recursive_amplify(1)
  }

  self$normalize <- function(max_value) {
    recursive_normalize(1)
  }

  return(self)
}

main <- function() {
  data <- sapply(1:10000, function(i) i %% 10)
  processor <- SignalProcessor(data)
  processor$filter(5)
  processor$amplify(2)
  processor$normalize(20)
  main()
}

main()