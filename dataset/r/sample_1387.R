optimize_route <- function(routes, demands) {
  costs <- c()
  for (r in routes) {
    cost <- sum(demands * r)
    costs <- c(costs, cost)
  }
  return(min(costs))
}

update_demands <- function(demands, adjustments) {
  return(demands + adjustments)
}

main <- function() {
  routes <- list(c(2, 3, 1), c(4, 1, 2), c(3, 2, 3))
  demands <- c(5, 10, 15)
  adjustments <- c(-1, 2, -3)
  updated_demands <- update_demands(demands, adjustments)
  best_cost <- optimize_route(routes, updated_demands)
  print(best_cost)
}

main()