simulate_stock_price <- function(steps, initial_price, drift, volatility) {
  price <- initial_price
  for (i in 1:steps) {
    price <- price * (1 + drift + volatility * rnorm(1, 0, 1))
  }
  return(price)
}

price_option <- function(pricing_function, initial_price, strike_price, steps, drift, volatility, simulations) {
  total <- 0
  for (i in 1:simulations) {
    final_price <- simulate_stock_price(steps, initial_price, drift, volatility)
    payoff <- max(final_price - strike_price, 0)
    total <- total + payoff
  }
  return(total / simulations)
}

main <- function() {
  initial_price <- 100
  strike_price <- 100
  steps <- 100
  drift <- 0.0001
  volatility <- 0.01
  simulations <- 10000
  option_price <- price_option(simulate_stock_price, initial_price, strike_price, steps, drift, volatility, simulations)
  cat('Option Price:', option_price, '\n')
}

main()