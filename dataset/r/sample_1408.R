RewardDecay <- setRefClass(
  "RewardDecay",
  fields = list(
    current_reward = "numeric",
    decay_rate = "numeric"
  ),
  methods = list(
    initialize = function(initial_reward, decay_rate) {
      .self$current_reward <- initial_reward
      .self$decay_rate <- decay_rate
    },
    update_reward = function() {
      .self$current_reward <<- .self$current_reward * (1 - .self$decay_rate)
    },
    get_current_reward = function() {
      return(.self$current_reward)
    }
  )
)

Agent <- setRefClass(
  "Agent",
  fields = list(
    reward_decay = "RewardDecay",
    action_count = "numeric"
  ),
  methods = list(
    initialize = function(reward_decay) {
      .self$reward_decay <- reward_decay
      .self$action_count <- 0
    },
    take_action = function() {
      .self$action_count <<- .self$action_count + 1
      .self$reward_decay$update_reward()
    },
    get_reward = function() {
      return(.self$reward_decay$get_current_reward())
    }
  )
)

simulate_environment <- function(agent, max_actions) {
  rewards <- c()
  for (i in 1:max_actions) {
    agent$take_action()
    rewards <- c(rewards, agent$get_reward())
  }
  return(rewards)
}

main <- function() {
  initial_reward <- 1.0
  decay_rate <- 0.01
  max_actions <- 1000
  reward_decay <- new("RewardDecay", initial_reward = initial_reward, decay_rate = decay_rate)
  agent <- new("Agent", reward_decay = reward_decay)
  rewards <- simulate_environment(agent, max_actions)
  print(rewards)
}

main()