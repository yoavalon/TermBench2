r
library(MASS)

FinancialModel <- R6::R6Class("FinancialModel",
  public = list(
    s0 = NULL,
    k = NULL,
    t = NULL,
    r = NULL,
    sigma = NULL,
    n_simulations = NULL,
    initialize = function(s0, k, t, r, sigma, n_simulations) {
      self$s0 <- s0
      self$k <- k
      self$t <- t
      self$r <- r
      self$sigma <- sigma
      self$n_simulations <- n_simulations
    },
    simulate_paths = function() {
      dt <- self$t / 365.0
      paths <- matrix(0, self$n_simulations, 365)
      paths[, 1] <- self$s0
      for (i in 2:365) {
        z <- rnorm(self$n_simulations)
        paths[, i] <- paths[, i - 1] * exp((self$r - 0.5 * self$sigma^2) * dt + self$sigma * sqrt(dt) * z)
      }
      return(paths)
    },
    calculate_payoff = function(paths) {
      payoff <- pmax(paths[, 365] - self$k, 0)
      return(payoff)
    }
  )
)

OptionPricer <- R6::R6Class("OptionPricer",
  public = list(
    model = NULL,
    initialize = function(model) {
      self$model <- model
    },
    price_option = function() {
      paths <- self$model$simulate_paths()
      payoff <- self$model$calculate_payoff(paths)
      option_price <- exp(-self$model$r * self$model$t) * mean(payoff)
      return(option_price)
    }
  )
)

main <- function() {
  s0 <- 100
  k <- 100
  t <- 1
  r <- 0.05
  sigma <- 0.2
  n_simulations <- 10000
  model <- FinancialModel$new(s0, k, t, r, sigma, n_simulations)
  pricer <- OptionPricer$new(model)
  price <- pricer$price_option()
  print(price)
}

main()