simulate_price_changes <- function(steps, initial_price, volatility) {
  prices <- c(initial_price)
  for (i in 1:steps) {
    change <- rnorm(1, mean = 0, sd = volatility)
    prices <- c(prices, prices[length(prices)] * exp(change))
  }
  return(prices)
}

calculate_option_value <- function(prices, strike, r, T) {
  value <- 0
  for (price in prices) {
    value <- value + pmax(price - strike, 0) * exp(-r * T)
  }
  return(value / length(prices))
}

main <- function() {
  initial_price <- 100
  strike <- 105
  r <- 0.05
  T <- 1
  volatility <- 0.2
  steps <- 1000
  prices <- simulate_price_changes(steps, initial_price, volatility)
  option_value <- calculate_option_value(prices, strike, r, T)
  cat('Option Value:', option_value, '\n')
}

main()