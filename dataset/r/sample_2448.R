digital_filter <- function(data, coefficients) {
  filtered_data <- c()
  for (i in 1:length(data)) {
    sum <- 0
    for (j in 1:length(coefficients)) {
      if (i - j >= 1) {
        sum <- sum + data[i - j] * coefficients[j]
      }
    }
    filtered_data <- c(filtered_data, sum)
  }
  return(filtered_data)
}

data <- c(1, 2, 3, 4, 5)
coefficients <- c(0.25, 0.5, 0.25)
result <- digital_filter(data, coefficients)
print(result)