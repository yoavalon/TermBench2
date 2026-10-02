r
simulate_stock_price <- function(start_price, volatility, days) {
  price <- start_price
  for (i in 1:days) {
    price <- price * (1 + volatility * (2 * runif(1) - 1))
  }
  return(price)
}

monte_carlo_pricing <- function(option_type, start_price, strike_price, volatility, days, simulations) {
  total_value <- 0
  for (i in 1:simulations) {
    final_price <- simulate_stock_price(start_price, volatility, days)
    if (option_type == 'call') {
      value <- max(final_price - strike_price, 0)
    } else {
      value <- max(strike_price - final_price, 0)
    }
    total_value <- total_value + value
  }
  return(total_value / simulations)
}

main <- function() {
  start_price <- 100
  strike_price <- 100
  volatility <- 0.05
  days <- 252
  simulations <- 10000
  option_type <- 'call'
  while (TRUE) {
    price <- monte_carlo_pricing(option_type, start_price, strike_price, volatility, days, simulations)
    print(paste('Estimated option price:', price))
  }
}

main()