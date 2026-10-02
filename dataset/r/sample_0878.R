library(stats)

OptionPricing <- R6::R6Class("OptionPricing",
  public = list(
    S = NULL,
    K = NULL,
    T = NULL,
    r = NULL,
    sigma = NULL,
    initialize = function(S, K, T, r, sigma) {
      self$S <- S
      self$K <- K
      self$T <- T
      self$r <- r
      self$sigma <- sigma
    },
    calculate_price = function(n_simulations, depth) {
      if (depth == 0) {
        return(self$black_scholes(self$S, self$K, self$T, self$r, self$sigma))
      } else {
        return(self$monte_carlo(n_simulations, depth))
      }
    },
    black_scholes = function(S, K, T, r, sigma) {
      d1 <- (log(S / K) + (r + 0.5 * sigma^2) * T) / (sigma * sqrt(T))
      d2 <- d1 - sigma * sqrt(T)
      return(S * exp(-r * T) * self$norm_cdf(d1) - K * exp(-r * T) * self$norm_cdf(d2))
    },
    norm_cdf = function(x) {
      return((1.0 + pnorm(x / sqrt(2.0))) / 2.0)
    },
    monte_carlo = function(n_simulations, depth) {
      payoff_sum <- 0
      for (i in 1:n_simulations) {
        price_path <- self$price_path_simulation()
        payoff_sum <- payoff_sum + max(price_path[length(price_path)] - self$K, 0)
      }
      return(payoff_sum / n_simulations * exp(-self$r * self$T))
    },
    price_path_simulation = function() {
      path <- c(self$S)
      for (i in 1:floor(self$T)) {
        drift <- self$r * path[length(path)] * (1 / 252)
        diffusion <- path[length(path)] * self$sigma * sqrt(1 / 252) * rnorm(1, 0, 1)
        path <- c(path, path[length(path)] + drift + diffusion)
      }
      return(path)
    }
  )
)

main <- function() {
  S <- 100
  K <- 100
  T <- 1
  r <- 0.05
  sigma <- 0.2
  n_simulations <- 1000
  depth <- 2
  pricing_model <- OptionPricing$new(S, K, T, r, sigma)
  option_price <- pricing_model$calculate_price(n_simulations, depth)
  print(paste('Option Price:', option_price))
}

main()