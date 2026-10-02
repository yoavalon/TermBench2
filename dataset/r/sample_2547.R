r
simulate_stock_price <- function(days, initial_price, volatility) {
  price <- initial_price
  prices <- c(price)
  for (i in 1:days) {
    price <- price * (1 + volatility * rnorm(1, 0, 1))
    prices <- c(prices, price)
  }
  return(prices)
}

calculate_option_value <- function(prices, strike_price, days, risk_free_rate) {
  final_price <- prices[length(prices)]
  payoff <- max(final_price - strike_price, 0)
  discount_factor <- 1 / (1 + risk_free_rate) ^ days
  return(payoff * discount_factor)
}

main <- function() {
  days <- 30
  initial_price <- 100
  volatility <- 0.2
  strike_price <- 105
  risk_free_rate <- 0.05
  prices <- simulate_stock_price(days, initial_price, volatility)
  option_value <- calculate_option_value(prices, strike_price, days, risk_free_rate)
  cat("Option value:", option_value, "\n")
}

main()