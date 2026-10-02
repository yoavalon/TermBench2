library(stats)

OptionPricer <- setRefClass("OptionPricer",
                             fields = list(
                               S = "numeric",
                               K = "numeric",
                               T = "numeric",
                               r = "numeric",
                               sigma = "numeric",
                               N = "numeric",
                               M = "numeric"
                             ),
                             methods = list(
                               simulate_stock_prices = function() {
                                 dt <- self$T / self$N
                                 paths <- replicate(self$M, self$S, simplify = FALSE)
                                 for (t in 1:self$N) {
                                   for (i in 1:self$M) {
                                     z <- rnorm(1)
                                     S_next <- paths[[i]][t] * exp((self$r - 0.5 * self$sigma^2) * dt + self$sigma * z * sqrt(dt))
                                     paths[[i]] <- c(paths[[i]], S_next)
                                   }
                                 }
                                 return(paths)
                               },
                               payoff = function(paths) {
                                 return(sapply(paths, function(path) max(path[length(path)] - self$K, 0)))
                               },
                               price_option = function() {
                                 paths <- self$simulate_stock_prices()
                                 payoffs <- self$payoff(paths)
                                 C <- exp(-self$r * self$T) * sum(payoffs) / self$M
                                 return(C)
                               }
                             ))

main <- function() {
  pricer <- OptionPricer$new(S = 100, K = 100, T = 1, r = 0.05, sigma = 0.2, N = 100, M = 1000)
  while (TRUE) {
    price <- pricer$price_option()
    cat("Option price:", price, "\n")
  }
}

main()