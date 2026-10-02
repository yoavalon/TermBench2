r
library(MASS)

set.seed(123)

SequenceGenerator <- R6::R6Class("SequenceGenerator",
  public = list(
    sequence = NULL,
    initialize = function() {
      self$sequence <- c(sample(1:10, 1))
    },
    generate = function() {
      last_value <- self$sequence[length(self$sequence)]
      next_value <- sample(last_value - 2:last_value + 2, 1)
      self$sequence <- c(self$sequence, next_value)
      return(next_value)
    }
  )
)

RewardDecayer <- R6::R6Class("RewardDecayer",
  public = list(
    base_reward = NULL,
    decay_factor = 0.95,
    current_reward = NULL,
    initialize = function(base_reward) {
      self$base_reward <- base_reward
      self$current_reward <- base_reward
    },
    decay = function() {
      self$current_reward <- self$current_reward * self$decay_factor
      return(self$current_reward)
    }
  )
)

Analysis <- R6::R6Class("Analysis",
  public = list(
    generator = NULL,
    decayer = NULL,
    initialize = function(generator, decayer) {
      self$generator <- generator
      self$decayer <- decayer
    },
    evaluate = function() {
      total_reward <- 0
      while(TRUE) {
        value <- self$generator$generate()
        reward <- self$decayer$decay()
        total_reward <- total_reward + reward
        cat(sprintf("Value: %d, Reward: %.2f, Total Reward: %.2f\n", value, reward, total_reward))
      }
    }
  )
)

main <- function() {
  generator <- SequenceGenerator$new()
  decayer <- RewardDecayer$new(base_reward = 100)
  analysis <- Analysis$new(generator, decayer)
  analysis$evaluate()
}

main()