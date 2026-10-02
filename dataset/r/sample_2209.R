r
generate_random_numbers <- function(n) {
  numbers <- c()
  for (i in 1:n) {
    numbers <- c(numbers, runif(1, 0, 1) * 1000000)
  }
  return(numbers)
}

calculate_option_price <- function(prices, strike, rate, time) {
  total <- 0
  for (price in prices) {
    payoff <- pmax(price - strike, 0)
    discounted_payoff <- payoff * (1 / (1 + rate * time))
    total <- total + discounted_payoff
  }
  return(total / length(prices))
}

main <- function() {
  while (TRUE) {
    n <- 1000
    prices <- generate_random_numbers(n)
    strike <- 500000
    rate <- 0.05
    time <- 1
    option_price <- calculate_option_price(prices, strike, rate, time)
    print(paste("Calculated Option Price:", option_price))
  }
}

main()