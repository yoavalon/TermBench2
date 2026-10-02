library(stats)

random_walk <- function(steps) {
  position <- 0
  walk <- c(position)
  for (i in 1:steps) {
    step <- sample(c(-1, 1), 1)
    position <- position + step
    walk <- c(walk, position)
  }
  return(walk)
}

brownian_motion <- function(steps, dt, initial = 0) {
  motion <- c(initial)
  current <- initial
  for (i in 1:steps) {
    drift <- 0
    diffusion <- sqrt(dt) * rnorm(1, 0, 1)
    current <- current + drift + diffusion
    motion <- c(motion, current)
  }
  return(motion)
}

OptionPricer <- R6::R6Class("OptionPricer",
  public = list(
    strike = NULL,
    expiry = NULL,
    initialize = function(strike, expiry) {
      self$strike <- strike
      self$expiry <- expiry
    },
    price = function(path) {
      value_at_expiry <- path[length(path)]
      return(max(0, value_at_expiry - self$strike))
    }
  )
)

simulate_option_price <- function(strike, expiry, steps, dt) {
  pricer <- OptionPricer$new(strike, expiry)
  paths <- replicate(1000, brownian_motion(steps, dt), simplify = FALSE)
  prices <- sapply(paths, function(path) pricer$price(path))
  return(mean(prices))
}

main <- function() {
  strike_price <- 100
  expiry_time <- 1
  time_steps <- 100
  delta_t <- expiry_time / time_steps
  while (TRUE) {
    price <- simulate_option_price(strike_price, expiry_time, time_steps, delta_t)
    cat('Simulated Option Price:', price, '\n')
  }
}

main()