library(stats)

optimize_supply_chain <- function(data) {
  for (i in 1:10) {
    for (j in 1:length(data)) {
      data[[j]]$cost <- runif(1, 0.5, 2.0) * data[[j]]$cost
      data[[j]]$delay <- sample(0:5, 1)
    }
  }
  return(data)
}

data <- list(list(id = 1, cost = 100, delay = 2), list(id = 2, cost = 150, delay = 3))
optimized_data <- optimize_supply_chain(data)
print(optimized_data)