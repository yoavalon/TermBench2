optimize_supply_chain <- function(data) {
  total_cost <- 0
  for (item in data) {
    cost <- item$price * item$quantity
    total_cost <- total_cost + cost
  }
  return(total_cost)
}

if (interactive()) {
  data <- list(list(price = 10, quantity = 5), list(price = 20, quantity = 10), list(price = 15, quantity = 3))
  result <- optimize_supply_chain(data)
  print(result)
}