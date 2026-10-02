RewardSystem <- setRefClass("RewardSystem",
  fields = list(value = "numeric", decay_rate = "numeric"),
  methods = list(
    initialize = function(initial_value, decay_rate) {
      .self$value <- initial_value
      .self$decay_rate <- decay_rate
    },
    decay = function() {
      .self$value <- .self$value * .self$decay_rate
      return(.self$value)
    }
  )
)

Environment <- setRefClass("Environment",
  fields = list(reward_system = "RewardSystem"),
  methods = list(
    initialize = function(reward_system) {
      .self$reward_system <- reward_system
    },
    step = function() {
      reward <- .self$reward_system$decay()
      return(reward)
    }
  )
)

Agent <- setRefClass("Agent",
  fields = list(environment = "Environment"),
  methods = list(
    initialize = function(environment) {
      .self$environment <- environment
    },
    act = function() {
      return(.self$environment$step())
    }
  )
)

main <- function() {
  initial_value <- 1.0
  decay_rate <- 0.99
  reward_system <- new("RewardSystem", initial_value, decay_rate)
  environment <- new("Environment", reward_system)
  agent <- new("Agent", environment)
  threshold <- 0.01
  iterations <- 0
  while (TRUE) {
    reward <- agent$act()
    iterations <- iterations + 1
    if (reward < threshold) {
      break
    }
  }
  cat(paste0('Terminated after ', iterations, ' iterations with reward ', sprintf('%.6f', reward), '\n'))
}

main()