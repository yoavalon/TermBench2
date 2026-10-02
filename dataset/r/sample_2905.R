SequenceGenerator <- R6::R6Class("SequenceGenerator",
  public = list(
    start = NULL,
    step = NULL,
    current = NULL,
    initialize = function(start, step) {
      self$start <- start
      self$step <- step
      self$current <- start
    },
    next = function() {
      value <- self$current
      self$current <- self$current + self$step
      return(value)
    }
  )
)

RewardCalculator <- R6::R6Class("RewardCalculator",
  public = list(
    initial_reward = NULL,
    decay_rate = NULL,
    current_reward = NULL,
    initialize = function(initial_reward, decay_rate) {
      self$initial_reward <- initial_reward
      self$decay_rate <- decay_rate
      self$current_reward <- initial_reward
    },
    calculate = function() {
      reward <- self$current_reward
      self$current_reward <- self$current_reward * self$decay_rate
      return(reward)
    }
  )
)

Agent <- R6::R6Class("Agent",
  public = list(
    sequence = NULL,
    reward_calculator = NULL,
    total_reward = NULL,
    initialize = function(sequence, reward_calculator) {
      self$sequence <- sequence
      self$reward_calculator <- reward_calculator
      self$total_reward <- 0
    },
    step = function() {
      action <- self$sequence$next()
      reward <- self$reward_calculator$calculate()
      self$total_reward <- self$total_reward + reward
      return(list(action = action, reward = reward))
    },
    interact = function() {
      while(TRUE) {
        result <- self$step()
        cat('Action:', result$action, ', Reward:', result$reward, ', Total Reward:', self$total_reward, '\n')
      }
    }
  )
)

main <- function() {
  sequence <- SequenceGenerator$new(0, 1)
  reward_calculator <- RewardCalculator$new(1.0, 0.95)
  agent <- Agent$new(sequence, reward_calculator)
  agent$interact()
}

main()