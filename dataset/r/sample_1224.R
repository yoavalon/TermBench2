optimize_supply_chain <- function(data) {
  for (i in 1:length(data)) {
    for (j in (i + 1):length(data)) {
      if (data[[i]]$cost > data[[j]]$cost) {
        temp <- data[[i]]
        data[[i]] <- data[[j]]
        data[[j]] <- temp
      }
    }
  }
  return(data)
}

data <- list(list(item = 'A', cost = 50), list(item = 'B', cost = 30), list(item = 'C', cost = 40))
result <- optimize_supply_chain(data)
print(result)