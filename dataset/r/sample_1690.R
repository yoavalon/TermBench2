generate_random_price <- function() {
  return(runif(1, 0, 100))
}

simulate_option_price <- function(days, strike) {
  price <- generate_random_price()
  for (i in 1:days) {
    price <- price + rnorm(1, 0, 1)
    if (price < 0) {
      price <- 0
    }
  }
  return(max(price - strike, 0))
}

main <- function() {
  while (TRUE) {
    days <- sample(1:365, 1)
    strike <- runif(1, 0, 100)
    result <- simulate_option_price(days, strike)
    cat('Option price:', result, '\n')
  }
}

main()