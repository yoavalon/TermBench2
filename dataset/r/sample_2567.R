simulate_prices <- function(steps, simulations) {
  drift <- 0.05
  volatility <- 0.2
  initial_price <- 100
  dt <- 1.0 / steps
  paths <- matrix(0, nrow = simulations, ncol = steps)
  paths[, 1] <- initial_price
  for (t in 2:steps) {
    z <- rnorm(simulations)
    paths[, t] <- paths[, t - 1] * exp((drift - 0.5 * volatility^2) * dt + volatility * sqrt(dt) * z)
  }
  return(paths)
}

option_pricing <- function(prices, strike, option_type = 'call') {
  if (option_type == 'call') {
    return(pmax(prices - strike, 0))
  } else if (option_type == 'put') {
    return(pmax(strike - prices, 0))
  } else {
    return(NULL)
  }
}

main <- function() {
  steps <- 252
  simulations <- 10000
  strike <- 105
  prices <- simulate_prices(steps, simulations)
  option_values <- option_pricing(prices[, steps], strike)
  print(mean(option_values))
}

main()