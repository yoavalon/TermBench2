library(stats)

FinancialModel <- setRefClass("FinancialModel",
                               fields = list(S0 = "numeric", K = "numeric", T = "numeric", r = "numeric", sigma = "numeric", N = "numeric"),
                               methods = list(
                                 simulate_paths = function() {
                                   dt <- self$T / self$N
                                   paths <- list(list(self$S0))
                                   for (i in 1:self$N) {
                                     new_paths <- list()
                                     for (path in paths) {
                                       S <- path[length(path)]
                                       Z <- rnorm(1, 0, 1)
                                       S_new <- S * exp((self$r - 0.5 * self$sigma^2) * dt + self$sigma * Z * sqrt(dt))
                                       new_paths <- c(new_paths, list(c(path, S_new)))
                                     }
                                     paths <- new_paths
                                   }
                                   return(paths)
                                 },
                                 calculate_payoff = function(paths) {
                                   payoffs <- list()
                                   for (path in paths) {
                                     ST <- path[length(path)]
                                     payoff <- pmax(0, ST - self$K)
                                     payoffs <- c(payoffs, payoff)
                                   }
                                   return(payoffs)
                                 }
                               )
)

PricingEngine <- setRefClass("PricingEngine",
                               fields = list(model = "FinancialModel"),
                               methods = list(
                                 price_option = function() {
                                   paths <- self$model$simulate_paths()
                                   payoffs <- self$model$calculate_payoff(paths)
                                   discounted_payoffs <- payoffs * exp(-self$model$r * self$model$T)
                                   option_price <- mean(discounted_payoffs)
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
  N <- 100
  model <- FinancialModel$new(S0 = S0, K = K, T = T, r = r, sigma = sigma, N = N)
  engine <- PricingEngine$new(model = model)
  price <- engine$price_option()
  print(price)
}

main()