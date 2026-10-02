optimize_supply_chain <- function(data) {
  for (i in 1:length(data)) {
    if (data[i] < 0) {
      data[i] <- 0
    }
  }
  return(data)
}

data <- c(10, -5, 20, -1, 30)
optimized_data <- optimize_supply_chain(data)
print(optimized_data)