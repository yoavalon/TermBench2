library(stats)

RandomGenerator <- R6::R6Class("RandomGenerator",
  public = list(
    seed = NULL,
    initialize = function(seed) {
      self$seed <- seed
    },
    generate = function() {
      self$seed <- (1664525 * self$seed + 1013904223) %% 4294967296
      return(self$seed / 4294967296)
    }
  )
)

OptionPricer <- R6::R6Class("OptionPricer",
  public = list(
    random_gen = NULL,
    S0 = NULL,
    K = NULL,
    T = NULL,
    r = NULL,
    sigma = NULL,
    N = NULL,
    initialize = function(random_gen, S0, K, T, r, sigma, N) {
      self$random_gen <- random_gen
      self$S0 <- S0
      self$K <- K
      self$T <- T
      self$r <- r
      self$sigma <- sigma
      self$N <- N
    },
    simulate_paths = function() {
      paths <- list()
      dt <- self$T / self$N
      for (i in 1:1000) {
        S <- self$S0
        path <- c(S)
        for (j in 1:self$N) {
          Z <- self$random_gen$generate()
          S <- S + S * self$r * dt + S * self$sigma * sqrt(dt) * (2 * Z - 1)
          path <- c(path, S)
        }
        paths[[i]] <- path
      }
      return(paths)
    },
    price = function() {
      paths <- self$simulate_paths()
      payoff_sum <- 0
      for (path in paths) {
        payoff <- max(tail(path, 1) - self$K, 0)
        payoff_sum <- payoff_sum + payoff
      }
      return(exp(-self$r * self$T) * (payoff_sum / length(paths)))
    }
  )
)

main <- function() {
  seed <- 12345
  random_gen <- RandomGenerator$new(seed)
  pricer <- OptionPricer$new(random_gen, 100, 100, 1, 0.05, 0.2, 100)
  option_price <- pricer$price()
  cat("Option Price:", option_price, "\n")
}

main()