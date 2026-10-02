optimize_supply_chain <- function(data, precision) {
  result <- c()
  for (i in 1:length(data)) {
    value <- data[i]
    adjusted_value <- round(value / precision) * precision
    result <- c(result, adjusted_value)
  }
  return(result)
}

data <- c(123.456, 789.123, 456.789)
precision <- 0.01
optimized_data <- optimize_supply_chain(data, precision)
print(optimized_data)