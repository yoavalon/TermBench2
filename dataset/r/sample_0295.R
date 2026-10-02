library(Matrix)

FinancialModel <- setRefClass("FinancialModel",
  fields = list(S0 = "numeric", K = "numeric", T = "numeric", r = "numeric", sigma = "numeric", N = "numeric", dt = "numeric"),
  methods = list(
    initialize = function(S0, K, T, r, sigma, N) {
      .self$S0 <- S0
      .self$K <- K
      .self$T <- T
      .self$r <- r
      .self$sigma <- sigma
      .self$N <- N
      .self$dt <- T / N
    },
    simulate_paths = function() {
      paths <- matrix(0, nrow = self$N + 1, ncol = length(self$S0))
      paths[1, ] <- self$S0
      for (t in 2:(self$N + 1)) {
        z <- rnorm(length(self$S0))
        paths[t, ] <- paths[t - 1, ] * exp((self$r - 0.5 * self$sigma^2) * self$dt + self$sigma * sqrt(self$dt) * z)
      }
      return(paths)
    },
    payoff = function(paths) {
      payoff <- pmax(paths[nrow(paths), ] - self$K, 0)
      return(payoff)
    }
  )
)

OptionPricer <- setRefClass("OptionPricer",
  fields = list(financial_model = "FinancialModel", M = "numeric"),
  methods = list(
    initialize = function(financial_model, M) {
      .self$financial_model <- financial_model
      .self$M <- M
    },
    price_option = function() {
      payoffs <- numeric(self$M)
      for (i in 1:self$M) {
        paths <- self$financial_model$simulate_paths()
        payoffs[i] <- self$financial_model$payoff(paths)
      }
      option_price <- exp(-self$financial_model$r * self$financial_model$T) * mean(payoffs)
      return(option_price)
    }
  )
)

main <- function() {
  S0 <- c(100, 100, 100)
  K <- 100
  T <- 1.0
  r <- 0.05
  sigma <- 0.2
  N <- 100
  M <- 10000
  financial_model <- FinancialModel$new(S0, K, T, r, sigma, N)
  option_pricer <- OptionPricer$new(financial_model, M)
  print(option_pricer$price_option())
}

main()