library(stats)

FinancialModel <- setRefClass("FinancialModel",
                              fields = list(S0 = "numeric", K = "numeric", T = "numeric", r = "numeric", sigma = "numeric", N = "numeric"),
                              methods = list(
                                simulate_paths = function() {
                                  paths <- list()
                                  for (i in 1:self$N) {
                                    path <- c(self$S0)
                                    for (j in 1:(self$T * 252)) {
                                      S_next <- path[length(path)] * (1 + rnorm(1, 0, self$sigma) * 252^(-0.5))
                                      path <- c(path, S_next)
                                    }
                                    paths[[i]] <- path
                                  }
                                  return(paths)
                                },
                                calculate_payoffs = function(paths) {
                                  payoffs <- c()
                                  for (path in paths) {
                                    payoff <- pmax(0, tail(path, 1) - self$K)
                                    payoffs <- c(payoffs, payoff)
                                  }
                                  return(payoffs)
                                }
                              ))

OptionPricer <- setRefClass("OptionPricer",
                             fields = list(model = "FinancialModel"),
                             methods = list(
                               price_option = function() {
                                 paths <- self$model$simulate_paths()
                                 payoffs <- self$model$calculate_payoffs(paths)
                                 discounted_payoffs <- payoffs * 252^(-self$model$r)
                                 return(mean(discounted_payoffs))
                               }
                             ))

main <- function() {
  S0 <- 100
  K <- 100
  T <- 1
  r <- 0.05
  sigma <- 0.2
  N <- 10000
  model <- FinancialModel$new(S0 = S0, K = K, T = T, r = r, sigma = sigma, N = N)
  pricer <- OptionPricer$new(model = model)
  option_price <- pricer$price_option()
  cat('Option Price:', option_price, '\n')
}

main()