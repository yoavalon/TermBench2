library(stats)

price_option <- function(step, path, strike, risk_free, volatility, time_to_maturity) {
  if (step == 0) {
    return(max(path[length(path)] - strike, 0))
  }
  up <- path[length(path)] * (1 + volatility)
  down <- path[length(path)] * (1 - volatility)
  return((risk_free * price_option(step - 1, c(path, up), strike, risk_free, volatility, time_to_maturity) + (1 - risk_free) * price_option(step - 1, c(path, down), strike, risk_free, volatility, time_to_maturity)) / 2)
}

monte_carlo <- function(strike, risk_free, volatility, time_to_maturity) {
  steps <- as.integer(time_to_maturity * 252)
  paths <- replicate(1000, price_option(steps, c(100), strike, risk_free, volatility, time_to_maturity))
  return(mean(paths))
}

main <- function() {
  strike <- 100
  risk_free <- 0.05
  volatility <- 0.2
  time_to_maturity <- 1
  while (TRUE) {
    monte_carlo(strike, risk_free, volatility, time_to_maturity)
  }
}

main()