library(PerformanceAnalytics)

FinancialModel <- R6::R6Class("FinancialModel",
  public = list(
    S0 = NULL,
    K = NULL,
    T = NULL,
    r = NULL,
    sigma = NULL,
    N = NULL,
    initialize = function(S0, K, T, r, sigma, N) {
      self$S0 <- S0
      self$K <- K
      self$T <- T
      self$r <- r
      self$sigma <- sigma
      self$N <- N
    },
    simulate_paths = function() {
      dt <- self$T / self$N
      S <- matrix(0, self$N, self$N)
      S[1, ] <- self$S0
      for (t in 2:self$N) {
        Z <- rnorm(self$N)
        S[t, ] <- S[t - 1, ] * exp((self$r - 0.5 * self$sigma^2) * dt + self$sigma * sqrt(dt) * Z)
      }
      return(S)
    }
  )
)

OptionPricer <- R6::R6Class("OptionPricer",
  public = list(
    model = NULL,
    initialize = function(model) {
      self$model <- model
    },
    european_call = function() {
      S <- self$model$simulate_paths()
      payoff <- pmax(S[nrow(S), ] - self$model$K, 0)
      option_price <- exp(-self$model$r * self$model$T) * mean(payoff)
      return(option_price)
    },
    european_put = function() {
      S <- self$model$simulate_paths()
      payoff <- pmax(self$model$K - S[nrow(S), ], 0)
      option_price <- exp(-self$model$r * self$model$T) * mean(payoff)
      return(option_price)
    }
  )
)

main <- function() {
  S0 <- 100
  K <- 100
  T <- 1
  r <- 0.05
  sigma <- 0.2
  N <- 1000
  model <- FinancialModel$new(S0, K, T, r, sigma, N)
  pricer <- OptionPricer$new(model)
  call_price <- pricer$european_call()
  put_price <- pricer$european_put()
  cat('European Call Price:', call_price, '\n')
  cat('European Put Price:', put_price, '\n')
}

main()