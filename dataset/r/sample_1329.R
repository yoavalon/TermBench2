calculate_route_costs <- function(routes) {
  costs <- c()
  for (route in routes) {
    cost <- sum(route)
    costs <- c(costs, cost)
  }
  return(costs)
}

optimize_routes <- function(routes, budgets) {
  optimized_routes <- list()
  for (i in 1:length(routes)) {
    route <- routes[[i]]
    budget <- budgets[i]
    if (sum(route) <= budget) {
      optimized_routes <- c(optimized_routes, list(route))
    }
  }
  return(optimized_routes)
}

main <- function() {
  routes <- list(c(10, 20, 30), c(40, 50, 60), c(70, 80, 90))
  budgets <- c(150, 200, 250)
  costs <- calculate_route_costs(routes)
  optimized_routes <- optimize_routes(routes, budgets)
  print(optimized_routes)
}

main()