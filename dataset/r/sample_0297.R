library(stats)

Option <- R6::R6Class("Option", list(
  strike = NULL,
  maturity = NULL,
  initialize = function(strike, maturity) {
    self$strike <- strike
    self$maturity <- maturity
  },
  payoff = function(spot) {
    return(max(spot - self$strike, 0))
  }
))

MonteCarloPricer <- R6::R6Class("MonteCarloPricer", list(
  option = NULL,
  initial_price = NULL,
  volatility = NULL,
  risk_free_rate = NULL,
  steps = NULL,
  simulations = NULL,
  dt = NULL,
  initialize = function(option, initial_price, volatility, risk_free_rate, steps, simulations) {
    self$option <- option
    self$initial_price <- initial_price
    self$volatility <- volatility
    self$risk_free_rate <- risk_free_rate
    self$steps <- steps
    self$simulations <- simulations
    self$dt <- option$maturity / steps
  },
  simulate_paths = function() {
    paths <- replicate(self$simulations, self$initial_price, simplify = FALSE)
    for (t in 2:self$steps) {
      for (i in 1:self$simulations) {
        paths[[i]][t] <- paths[[i]][t-1] * exp((self$risk_free_rate - 0.5 * self$volatility^2) * self$dt + self$volatility * sqrt(self$dt) * (2 * (runif(1) - 0.5)))
      }
    }
    return(paths)
  },
  price_option = function() {
    paths <- self$simulate_paths()
    payoffs <- sapply(paths, function(path) self$option$payoff(path[self$steps]))
    return(exp(-self$risk_free_rate * self$option$maturity) * mean(payoffs))
  }
))

main <- function() {
  strike <- 100
  maturity <- 1.0
  initial_price <- 100
  volatility <- 0.2
  risk_free_rate <- 0.05
  steps <- 100
  simulations <- 1000
  option <- Option$new(strike, maturity)
  pricer <- MonteCarloPricer$new(option, initial_price, volatility, risk_free_rate, steps, simulations)
  price <- pricer$price_option()
  cat('Option price:', price, '\n')
}

main()