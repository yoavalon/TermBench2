optimize_supply_chain <- function(costs, index, result) {
  if (index == length(costs)) {
    return(result)
  }
  min_cost <- min(costs[[index]])
  return(optimize_supply_chain(costs, index + 1, result + min_cost))
}

costs <- list(c(10, 20, 30), c(15, 25, 35), c(5, 15, 25))
print(optimize_supply_chain(costs, 1, 0))