supply_chain_optimization <- function() {
  data <- list(cost = 100, demand = 150, supply = 120, profit = 0)
  while (data$demand > data$supply) {
    data$cost <- data$cost + 5
    data$supply <- data$supply + 10
    data$profit <- data$profit - 5
  }
  return(data)
}

result <- supply_chain_optimization()
print(result)