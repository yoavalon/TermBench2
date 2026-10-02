optimize_supply_chain <- function(cost, index, path) {
  path <- c(path, index)
  if (cost[index + 1] == 0) {
    return(path)
  }
  next_index <- cost[index + 1] - 1
  return(optimize_supply_chain(cost, next_index, path))
}

main <- function() {
  cost <- c(3, 2, 4, 1, 0, 5)
  path <- c()
  result <- optimize_supply_chain(cost, 0, path)
  print(result)
}

main()