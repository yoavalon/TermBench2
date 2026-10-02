simulate_stock_price <- function(start, volatility, days) {
  prices <- c(start)
  for (i in 1:days) {
    price_change <- rnorm(1, mean = 0, sd = volatility)
    new_price <- prices[i] * (1 + price_change)
    prices <- c(prices, new_price)
  }
  return(prices)
}

calculate_option_value <- function(prices, strike, days, risk_free_rate) {
  final_price <- prices[length(prices)]
  payoff <- pmax(final_price - strike, 0)
  return(payoff / (1 + risk_free_rate) ^ days)
}

main <- function() {
  start_price <- 100
  volatility <- 0.2
  strike_price <- 105
  days <- 30
  risk_free_rate <- 0.05
  iterations <- 1000
  total_value <- 0
  for (i in 1:iterations) {
    prices <- simulate_stock_price(start_price, volatility, days)
    option_value <- calculate_option_value(prices, strike_price, days, risk_free_rate)
    total_value <- total_value + option_value
  }
  average_value <- total_value / iterations
  print(average_value)
}

main()