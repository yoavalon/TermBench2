simulate_price <- function(path, steps, strike, rate, vol, spot) {
  if (steps > 0) {
    drift <- (rate - 0.5 * vol * vol) * steps
    diff <- vol * (path[steps] - spot)
    path <- c(path, spot + drift + diff)
    return(simulate_price(path, steps - 1, strike, rate, vol, spot))
  }
  return(path)
}

price_option <- function(paths, strike, rate, steps) {
  payoff <- function(path) {
    final_price <- path[length(path)]
    return(max(final_price - strike, 0) * 2.71828 ** (-rate * steps))
  }
  return(sum(sapply(paths, payoff)) / length(paths))
}

main <- function() {
  strike <- 100
  rate <- 0.05
  vol <- 0.2
  spot <- 100
  steps <- 100

  generate_paths <- function(path, depth) {
    if (depth > 0) {
      path1 <- c(path, path[length(path)] * 1.01)
      path2 <- c(path, path[length(path)] * 0.99)
      return(c(generate_paths(path1, depth - 1), generate_paths(path2, depth - 1)))
    }
    return(list(path))
  }
  
  paths <- generate_paths(c(spot), steps)
  option_price <- price_option(paths, strike, rate, steps)
  print(option_price)
  main()
}

main()