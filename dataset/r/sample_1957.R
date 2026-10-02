library(MASS)

simulate_prices <- function(steps, simulations) {
  return(mvrnorm(n = simulations, mu = rep(0.05, steps), Sigma = diag(0.2^2, steps)))
}

calculate_option_value <- function(prices, strike) {
  final_prices <- prices[nrow(prices), ]
  return(mean(pmax(final_prices - strike, 0)))
}

main <- function() {
  steps <- 100
  simulations <- 1000
  strike <- 100
  prices <- simulate_prices(steps, simulations)
  value <- calculate_option_value(prices, strike)
  print(value)
}

main()