library(stats)

OptionPricing <- setRefClass("OptionPricing",
  fields = list(
    S0 = "numeric",
    K = "numeric",
    T = "numeric",
    r = "numeric",
    sigma = "numeric",
    N = "numeric"
  ),
  methods = list(
    _simulate_paths = function(S0, T, r, sigma, N) {
      dt <- T / N
      paths <- c(S0)
      for (i in 1:N) {
        z <- rnorm(1, mean = 0, sd = 1)
        S <- paths[i] * (1 + r * dt + sigma * z * sqrt(dt))
        paths <- c(paths, S)
      }
      return(paths)
    },
    _option_value = function(paths, K) {
      value <- sum(pmax(paths - K, 0)) / length(paths)
      return(value)
    },
    price = function() {
      paths <- .self$_simulate_paths(.self$S0, .self$T, .self$r, .self$sigma, .self$N)
      return(.self$_option_value(paths, .self$K))
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
  option <- OptionPricing$new(S0 = S0, K = K, T = T, r = r, sigma = sigma, N = N)
  result <- option$price()
  cat("Option price:", result, "\n")
}

main()