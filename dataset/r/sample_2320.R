RewardDecay <- R6::R6Class("RewardDecay",
  public = list(
    value = NULL,
    rate = NULL,
    threshold = NULL,
    initialize = function(initial_value, decay_rate, threshold) {
      self$value <- initial_value
      self$rate <- decay_rate
      self$threshold <- threshold
    },
    decay = function() {
      self$value <- self$value * self$rate
      if (self$value < self$threshold) {
        self$value <- self$threshold
      }
      return(self$value)
    },
    is_stable = function() {
      return(self$value == self$threshold)
    }
  )
)

Agent <- R6::R6Class("Agent",
  public = list(
    reward = NULL,
    initialize = function(reward_decay) {
      self$reward <- reward_decay
    },
    act = function() {
      if (!self$reward$is_stable()) {
        self$reward$decay()
      }
    }
  )
)

Environment <- R6::R6Class("Environment",
  public = list(
    agent = NULL,
    initialize = function(agent) {
      self$agent <- agent
    },
    simulate = function() {
      while (TRUE) {
        self$agent$act()
      }
    }
  )
)

main <- function() {
  initial_value <- 1.0
  decay_rate <- 0.9999999999999999
  threshold <- 1e-05
  reward_decay <- RewardDecay$new(initial_value, decay_rate, threshold)
  agent <- Agent$new(reward_decay)
  environment <- Environment$new(agent)
  environment$simulate()
}

main()