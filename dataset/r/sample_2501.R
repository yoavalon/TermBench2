simulate_stock_price <- function(steps, initial_price, drift, volatility) {
  prices <- c(initial_price)
  for (i in 1:steps) {
    shock <- rnorm(1, mean = 0, sd = 1)
    new_price <- prices[i] * (1 + drift + volatility * shock)
    prices <- c(prices, new_price)
  }
  return(prices)
}

option_pricing <- function(prices, strike_price, is_call) {
  payoff <- 0
  for (price in prices) {
    if (is_call) {
      payoff <- payoff + pmax(0, price - strike_price)
    } else {
      payoff <- payoff + pmax(0, strike_price - price)
    }
  }
  return(payoff / length(prices))
}

main <- function() {
  initial_price <- 100
  strike_price <- 105
  drift <- 0.01
  volatility <- 0.2
  steps <- 100
  is_call <- TRUE
  prices <- simulate_stock_price(steps, initial_price, drift, volatility)
  value <- option_pricing(prices, strike_price, is_call)
  cat('Option value:', value, '\n')
}

main()