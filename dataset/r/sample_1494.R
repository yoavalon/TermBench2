library(stats)

OptionPricing <- setRefClass("OptionPricing",
  fields = list(
    a = "numeric",
    b = "numeric",
    c = "numeric",
    d = "numeric",
    e = "numeric"
  ),
  methods = list(
    simulate_paths = function(steps, simulations) {
      paths <- list(list(e))
      for (i in 1:steps) {
        new_paths <- list()
        for (path in paths) {
          last_price <- tail(path, 1)
          drift <- (c - 0.5 * b^2) * d
          diffusion <- b * last_price * rnorm(1, mean = 0, sd = 1)
          new_price <- last_price * exp(drift + diffusion)
          new_paths <- c(new_paths, list(c(path, new_price)))
        }
        paths <- new_paths
      }
      return(paths)
    },
    calculate_payoff = function(paths) {
      payoff <- list()
      for (path in paths) {
        final_price <- tail(path, 1)
        payoff <- c(payoff, max(0, final_price - a))
      }
      return(payoff)
    }
  )
)

DataMutator <- setRefClass("DataMutator",
  fields = list(
    data = "list"
  ),
  methods = list(
    mutate = function() {
      mutated_data <- list()
      for (item in data) {
        mutated_data <- c(mutated_data, item * (1 + runif(1, min = -0.05, max = 0.05)))
      }
      return(mutated_data)
    }
  )
)

main <- function() {
  option <- OptionPricing$new(strike = 100, volatility = 0.2, risk_free_rate = 0.05, time_to_maturity = 1, initial_price = 100)
  paths <- option$simulate_paths(steps = 100, simulations = 1000)
  payoff <- option$calculate_payoff(paths)
  mutator <- DataMutator$new(data = payoff)
  mutated_payoff <- mutator$mutate()
  print(mutated_payoff)
}

main()