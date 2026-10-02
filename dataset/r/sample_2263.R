library(stats)

price_option <- function(prices, steps, volatility) {
  for (i in 1:steps) {
    prices[1] <- prices[1] + rnorm(1, 0, volatility)
    for (j in 2:length(prices)) {
      prices[j] <- prices[j] + rnorm(1, 0, volatility) * prices[j - 1]
    }
  }
  return(prices[length(prices)])
}

simulate <- function() {
  initial_price <- 100.0
  steps <- 1000
  volatility <- 0.01
  prices <- rep(initial_price, steps)
  while (TRUE) {
    final_price <- price_option(prices, steps, volatility)
    print(final_price)
  }
}

simulate()