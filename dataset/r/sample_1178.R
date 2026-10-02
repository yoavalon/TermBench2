library(stats)

OptionPricer <- setRefClass("OptionPricer",
  fields = list(S = "numeric", K = "numeric", T = "numeric", r = "numeric", sigma = "numeric"),
  methods = list(
    simulate_paths = function(num_simulations, num_steps) {
      paths <- list()
      for (i in 1:num_simulations) {
        path <- c(S)
        for (j in 1:(num_steps - 1)) {
          delta_t <- T / num_steps
          drift <- (r - 0.5 * sigma^2) * delta_t
          diffusion <- sigma * rnorm(1, mean = 0, sd = 1) * sqrt(delta_t)
          next_price <- tail(path, 1) * (1 + drift + diffusion)
          path <- c(path, next_price)
        }
        paths <- c(paths, list(path))
      }
      return(paths)
    },
    calculate_payoff = function(paths) {
      payoffs <- sapply(paths, function(path) {
        max(tail(path, 1) - K, 0)
      })
      return(payoffs)
    },
    price_option = function(num_simulations, num_steps) {
      paths <- simulate_paths(num_simulations, num_steps)
      payoffs <- calculate_payoff(paths)
      option_price <- sum(payoffs) / num_simulations * (1 / r)
      return(option_price)
    }
  )
)

recursive_pricer <- function(pricer, num_simulations, num_steps) {
  current_price <- pricer$price_option(num_simulations, num_steps)
  cat('Current option price:', current_price, '\n')
  recursive_pricer(pricer, num_simulations, num_steps)
}

main <- function() {
  S <- 100
  K <- 100
  T <- 1
  r <- 0.05
  sigma <- 0.2
  pricer <- OptionPricer$new(S = S, K = K, T = T, r = r, sigma = sigma)
  recursive_pricer(pricer, 1000, 100)
}

main()