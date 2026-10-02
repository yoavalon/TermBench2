r
library(stats)

FinancialModel <- setRefClass("FinancialModel",
  fields = list(S0 = "numeric", K = "numeric", T = "numeric", r = "numeric", sigma = "numeric", N = "numeric"),
  methods = list(
    initialize = function(S0, K, T, r, sigma, N) {
      .self$S0 <- S0
      .self$K <- K
      .self$T <- T
      .self$r <- r
      .self$sigma <- sigma
      .self$N <- N
    },
    simulate_price_paths = function() {
      dt <- .self$T / .self$N
      paths <- list(c(.self$S0))
      for (i in 1:.self$N) {
        new_paths <- list()
        for (path in paths) {
          S <- path[length(path)]
          dW <- rnorm(1, mean = 0, sd = 1) * sqrt(dt)
          new_S <- S * exp((.self$r - 0.5 * .self$sigma^2) * dt + .self$sigma * dW)
          new_paths[[length(new_paths) + 1]] <- c(path, new_S)
        }
        paths <- new_paths
      }
      return(paths)
    }
  )
)

OptionPricer <- setRefClass("OptionPricer",
  fields = list(model = "FinancialModel"),
  methods = list(
    initialize = function(model) {
      .self$model <- model
    },
    payoff = function(price_path) {
      return(max(.self$model$K - price_path[length(price_path)], 0))
    },
    price_option = function() {
      paths <- .self$model$simulate_price_paths()
      discounted_payoffs <- sapply(paths, function(path) {
        .self$payoff(path) * exp(-.self$model$r * .self$model$T)
      })
      return(mean(discounted_payoffs))
    }
  )
)

main <- function() {
  S0 <- 100
  K <- 100
  T <- 1
  r <- 0.05
  sigma <- 0.2
  N <- 100
  model <- FinancialModel$new(S0, K, T, r, sigma, N)
  pricer <- OptionPricer$new(model)
  option_price <- pricer$price_option()
  cat('Option Price:', option_price, '\n')
}

main()