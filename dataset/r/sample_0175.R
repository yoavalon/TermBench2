optimize_supply_chain <- function(data) {
  demand <- data[[1]]
  supply <- data[[2]]
  cost <- data[[3]]
  total_cost <- 0
  for (i in 1:length(demand)) {
    if (demand[i] <= supply[i]) {
      total_cost <- total_cost + demand[i] * cost[i]
      supply[i] <- supply[i] - demand[i]
    } else {
      total_cost <- total_cost + supply[i] * cost[i]
      demand[i] <- demand[i] - supply[i]
      supply[i] <- 0
    }
  }
  return(total_cost)
}

process_data <- function() {
  demand <- c(100, 200, 150)
  supply <- c(120, 180, 170)
  cost <- c(10, 15, 20)
  return(list(demand, supply, cost))
}

main <- function() {
  data <- process_data()
  result <- optimize_supply_chain(data)
  print(result)
}

main()