library(MASS)

Environment <- setRefClass("Environment",
  fields = list(
    num_states = "numeric",
    num_actions = "numeric"
  ),
  methods = list(
    initialize = function(num_states, num_actions) {
      .self$num_states <- num_states
      .self$num_actions <- num_actions
    },
    step = function(state, action) {
      reward <- .self$_compute_reward(state, action)
      next_state <- .self$_transition(state, action)
      done <- .self$_is_done(next_state)
      return(list(next_state = next_state, reward = reward, done = done))
    },
    _compute_reward = function(state, action) {
      return(-sqrt((state - action) ^ 2))
    },
    _transition = function(state, action) {
      return((state + action) %% .self$num_states)
    },
    _is_done = function(state) {
      return(state == 0)
    }
  )
)

Agent <- setRefClass("Agent",
  fields = list(
    num_actions = "numeric",
    policy = "numeric"
  ),
  methods = list(
    initialize = function(num_actions) {
      .self$num_actions <- num_actions
      .self$policy <- rep(1 / num_actions, num_actions)
    },
    select_action = function() {
      return(sample(1:.self$num_actions, 1, prob = .self$policy))
    },
    update_policy = function(state, action, reward) {
      .self$policy[action] <- .self$policy[action] + 0.1 * (reward - mean(.self$policy))
    }
  )
)

main <- function() {
  num_states <- 10
  num_actions <- 5
  max_steps <- 100
  gamma <- 0.99
  env <- Environment$new(num_states, num_actions)
  agent <- Agent$new(num_actions)
  state <- sample(1:num_states, 1)
  for (step in 1:max_steps) {
    action <- agent$select_action()
    step_result <- env$step(state, action)
    next_state <- step_result$next_state
    reward <- step_result$reward
    done <- step_result$done
    agent$update_policy(state, action, reward)
    state <- next_state
    if (done) {
      break
    }
  }
}

main()