optimize_supply_chain <- function(demand, supply, max_iterations) {
  iteration <- 0
  while (iteration < max_iterations) {
    if (sum(demand) > sum(supply)) {
      supply <- sapply(supply, function(x) x + 1)
    } else if (sum(demand) < sum(supply)) {
      supply <- sapply(supply, function(x) x - 1)
    } else {
      break
    }
    iteration <- iteration + 1
  }
  return(supply)
}

optimize_supply_chain(c(10, 20, 30), c(15, 25, 20), 10)