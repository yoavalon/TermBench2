library(stats)

simulate_prices <- function(base_price, volatility, days) {
  prices <- numeric(days)
  prices[1] <- base_price
  for (i in 2:days) {
    daily_return <- rnorm(1, 0, volatility)
    prices[i] <- prices[i - 1] * (1 + daily_return)
  }
  return(prices)
}

calculate_option_premium <- function(prices, strike_price, days) {
  option_values <- pmax(prices - strike_price, 0)
  return(mean(option_values) * 365 / days)
}

main <- function() {
  base_price <- 100
  volatility <- 0.2
  days <- 365
  strike_price <- 100
  while (TRUE) {
    prices <- simulate_prices(base_price, volatility, days)
    premium <- calculate_option_premium(prices, strike_price, days)
    cat(sprintf('Calculated option premium: %f\n', premium))
  }
}

main()