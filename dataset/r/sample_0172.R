r
generate_paths <- function(steps, simulations) {
  paths <- list()
  for (i in 1:simulations) {
    path <- c(0)
    for (j in 2:steps) {
      path <- c(path, path[j-1] + sample(c(-1, 1), 1))
    }
    paths[[i]] <- path
  }
  return(paths)
}

calculate_option_value <- function(paths, strike_price, payoff) {
  values <- c()
  for (path in paths) {
    final_price <- path[length(path)]
    values <- c(values, max(0, payoff * (final_price - strike_price)))
  }
  return(mean(values))
}

main <- function() {
  steps <- 100
  simulations <- 1000
  strike_price <- 50
  payoff <- 1
  paths <- generate_paths(steps, simulations)
  option_value <- calculate_option_value(paths, strike_price, payoff)
  cat('Option Value:', option_value, '\n')
}

main()