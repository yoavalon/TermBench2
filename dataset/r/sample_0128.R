simulate_option_price <- function(steps, drift, volatility, initial_price) {
  price <- initial_price
  for (i in 1:steps) {
    price <- price * (1 + drift + volatility * rnorm(1, 0, 1))
  }
  return(price)
}

is_terminating <- function(price, strike_price, call_put) {
  if (call_put == 'call') {
    return(price > strike_price)
  } else if (call_put == 'put') {
    return(price < strike_price)
  }
  return(FALSE)
}

main <- function() {
  initial_price <- 100
  strike_price <- 105
  drift <- 0.01
  volatility <- 0.2
  steps <- 100
  call_put <- 'call'
  price <- simulate_option_price(steps, drift, volatility, initial_price)
  result <- is_terminating(price, strike_price, call_put)
  print(result)
}

main()