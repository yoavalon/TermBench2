optimize_supply_chain <- function(data, precision) {
  result <- list()
  for (item in data) {
    adjusted_value <- round(item$value, precision)
    result <- c(result, list(id = item$id, adjusted_value = adjusted_value))
  }
  return(result)
}

data <- list(list(id = 1, value = 123.456789), list(id = 2, value = 987.654321))
precision <- 3
optimized_data <- optimize_supply_chain(data, precision)
print(optimized_data)