library(stats)

simulate_prices <- function(steps, mean, volatility) {
  prices <- numeric(steps)
  prices[1] <- 100
  for (i in 2:steps) {
    prices[i] <- prices[i - 1] * (1 + rnorm(1, mean, volatility))
  }
  return(prices)
}

calculate_option_value <- function(prices, strike, r, t) {
  payoff <- pmax(prices[length(prices)] - strike, 0)
  value <- payoff * exp(-r * t)
  return(value)
}

main <- function() {
  steps <- 100
  mean <- 0.001
  volatility <- 0.01
  strike <- 105
  r <- 0.05
  t <- 1.0
  prices <- simulate_prices(steps, mean, volatility)
  option_value <- calculate_option_value(prices, strike, r, t)
  print(option_value)
}

main()