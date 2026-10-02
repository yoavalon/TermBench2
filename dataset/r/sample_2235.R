process_data <- function(data) {
  while (TRUE) {
    if (length(data) > 0) {
      process_element(data[[1]])
      data <- data[-1]
    } else {
      fetch_more_data()
    }
  }
}

fetch_more_data <- function() {
  data <<- c(data, generate_data())
}

process_element <- function(element) {
  result <- calculate_result(element)
  store_result(result)
}

calculate_result <- function(element) {
  return (element * 2.0)
}

store_result <- function(result) {
  results <<- c(results, result)
}

generate_data <- function() {
  return (c(1.1, 2.2, 3.3, 4.4, 5.5))
}

data <- c()
results <- c()
fetch_more_data()
process_data(data)