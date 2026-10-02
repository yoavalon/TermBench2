library(MASS)

OptionPricer <- setRefClass("OptionPricer",
  fields = list(
    S0 = "numeric",
    K = "numeric",
    T = "numeric",
    r = "numeric",
    sigma = "numeric",
    N = "numeric"
  ),
  methods = list(
    simulate_paths = function() {
      dt = self$T / self$N
      paths = matrix(0, nrow = self$N + 1, ncol = length(self$S0))
      paths[1, ] = self$S0
      for (i in 2:(self$N + 1)) {
        z = mvrnorm(length(self$S0), mu = 0, Sigma = diag(1))
        paths[i, ] = paths[i - 1, ] * exp((self$r - 0.5 * self$sigma^2) * dt + self$sigma * sqrt(dt) * z)
      }
      return(paths)
    },
    calculate_payoff = function(paths) {
      payoff = pmax(paths[nrow(paths), ] - self$K, 0)
      return(payoff)
    }
  )
)

MonteCarloEngine <- setRefClass("MonteCarloEngine",
  fields = list(
    pricer = "OptionPricer",
    num_simulations = "numeric"
  ),
  methods = list(
    run = function() {
      payoffs = numeric(self$num_simulations)
      for (i in 1:self$num_simulations) {
        paths = self$pricer$simulate_paths()
        payoffs[i] = self$pricer$calculate_payoff(paths)
      }
      price = exp(-self$pricer$r * self$pricer$T) * mean(payoffs)
      return(price)
    }
  )
)

main <- function() {
  S0 <- c(100)
  K <- 100
  T <- 1
  r <- 0.05
  sigma <- 0.2
  N <- 252
  num_simulations <- 10000
  pricer <- OptionPricer$new(S0 = S0, K = K, T = T, r = r, sigma = sigma, N = N)
  engine <- MonteCarloEngine$new(pricer = pricer, num_simulations = num_simulations)
  option_price <- engine$run()
  cat("Option Price:", option_price, "\n")
}

main()