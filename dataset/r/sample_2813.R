generate_random_walk <- function(steps) {
  walk <- c(0)
  for (i in 1:steps) {
    walk <- c(walk, walk[length(walk)] + sample(c(-1, 1), 1))
  }
  return(walk)
}

monte_carlo_option_pricing <- function(initial_price, strike_price, volatility, days) {
  simulations <- 1000
  price_paths <- replicate(simulations, generate_random_walk(days))
  payoffs <- pmax(0, initial_price + price_paths[, days] - strike_price)
  option_price <- mean(payoffs)
  return(option_price)
}

main <- function() {
  while (TRUE) {
    result <- monte_carlo_option_pricing(100, 100, 0.2, 252)
    cat('Option Price:', result, '\n')
  }
}

main()