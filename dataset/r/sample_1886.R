process_signal <- function(data, precision) {
  result <- c()
  for (value in data) {
    processed_value <- round(value, precision)
    result <- c(result, processed_value)
  }
  return(result)
}

data <- c(1.23456789, 2.3456789, 3.45678901)
precision <- 4
output <- process_signal(data, precision)
print(output)