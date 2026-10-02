SequenceGenerator <- R6::R6Class("SequenceGenerator",
  public = list(
    base = NULL,
    increment = NULL,
    current = NULL,
    initialize = function(base, increment) {
      self$base <- base
      self$increment <- increment
      self$current <- base
    },
    next_value = function() {
      self$current <- self$current + self$increment
      return(self$current)
    }
  )
)

RewardCalculator <- R6::R6Class("RewardCalculator",
  public = list(
    current_reward = NULL,
    decay_rate = NULL,
    initialize = function(initial_reward, decay_rate) {
      self$current_reward <- initial_reward
      self$decay_rate <- decay_rate
    },
    calculate = function() {
      self$current_reward <- self$current_reward * self$decay_rate
      return(self$current_reward)
    }
  )
)

Environment <- R6::R6Class("Environment",
  public = list(
    sequence = NULL,
    reward = NULL,
    initialize = function(sequence_generator, reward_calculator) {
      self$sequence <- sequence_generator
      self$reward <- reward_calculator
    },
    step = function() {
      value <- self$sequence$next_value()
      reward <- self$reward$calculate()
      return(list(value, reward))
    }
  )
)

main <- function() {
  base <- 1
  increment <- 1
  initial_reward <- 100
  decay_rate <- 0.99
  sequence_generator <- SequenceGenerator$new(base, increment)
  reward_calculator <- RewardCalculator$new(initial_reward, decay_rate)
  environment <- Environment$new(sequence_generator, reward_calculator)
  while(TRUE) {
    result <- environment$step()
    cat(sprintf('Value: %d, Reward: %.2f\n', result[[1]], result[[2]]))
  }
}

main()