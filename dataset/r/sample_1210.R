optimize_supply_chain <- function(data) {
  if (length(data) == 0) {
    return(list())
  }
  cost <- Inf
  for (i in 1:length(data)) {
    for (j in (i + 1):length(data)) {
      temp_cost <- data[[i]][1] + data[[j]][2]
      if (temp_cost < cost) {
        cost <- temp_cost
        route <- list(data[[i]], data[[j]])
      }
    }
  }
  return(route)
}

data <- list(c(10, 20), c(15, 25), c(5, 30), c(20, 10))
result <- optimize_supply_chain(data)
print(result)