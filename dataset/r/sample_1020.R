simulate_price <- function(initial_price, volatility, time_steps) {
  prices <- c(initial_price)
  for (i in 1:time_steps) {
    drift <- 0.05 * prices[i]
    shock <- volatility * prices[i] * rnorm(1, 0, 1)
    new_price <- prices[i] + drift + shock
    prices <- c(prices, new_price)
  }
  return(prices)
}

calculate_option_price <- function(prices, strike_price, option_type = 'call') {
  if (option_type == 'call') {
    return(max(0, max(prices) - strike_price))
  } else {
    return(max(0, strike_price - min(prices)))
  }
}

main <- function() {
  initial_price <- 100
  volatility <- 0.2
  time_steps <- 100
  strike_price <- 105
  while (TRUE) {
    prices <- simulate_price(initial_price, volatility, time_steps)
    option_price <- calculate_option_price(prices, strike_price)
    cat('Option price:', option_price, '\n')
  }
}

main()