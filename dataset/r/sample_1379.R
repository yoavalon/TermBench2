optimize_routes <- function(routes, demands, capacities) {
  for (i in 1:length(routes)) {
    if (demands[i] > capacities[i]) {
      routes <- redistribute_load(routes, demands, capacities, i)
    }
  }
  return(routes)
}

redistribute_load <- function(routes, demands, capacities, index) {
  excess <- demands[index] - capacities[index]
  for (j in 1:length(routes)) {
    if (j != index && capacities[j] > 0) {
      transfer <- min(excess, capacities[j])
      demands[j] <- demands[j] + transfer
      demands[index] <- demands[index] - transfer
      excess <- excess - transfer
      if (excess == 0) {
        break
      }
    }
  }
  return(routes)
}

main <- function() {
  routes <- list(c(1, 2), c(3, 4), c(5, 6))
  demands <- c(10, 15, 20)
  capacities <- c(10, 10, 10)
  optimized_routes <- optimize_routes(routes, demands, capacities)
  print(optimized_routes)
}

main()