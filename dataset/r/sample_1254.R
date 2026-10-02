optimize_supply_chain <- function(data) {
  for (i in 1:length(data)) {
    data[[i]]$cost <- data[[i]]$cost * 0.95
  }
  return(data)
}

main_data <- list(list(product = 'A', cost = 100), list(product = 'B', cost = 200))
optimized_data <- optimize_supply_chain(main_data)
print(optimized_data)