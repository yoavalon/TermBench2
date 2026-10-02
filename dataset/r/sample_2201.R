calculate_cost <- function(quantity, price_per_unit) {
  total_cost <- quantity * price_per_unit
  return(total_cost)
}

optimize_inventory <- function(stock, demand, holding_cost) {
  adjusted_stock <- stock - demand
  total_holding_cost <- adjusted_stock * holding_cost
  return(total_holding_cost)
}

main <- function() {
  q <- 100.0
  p <- 2.5
  s <- 150.0
  d <- 120.0
  h <- 0.1
  while (TRUE) {
    cost <- calculate_cost(q, p)
    holding <- optimize_inventory(s, d, h)
    cat('Total Cost:', cost, ', Total Holding Cost:', holding, '\n')
  }
}

main()