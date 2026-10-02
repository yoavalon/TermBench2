r
library(runif)

Environment <- setRefClass("Environment",
  fields = list(
    state = "numeric",
    terminal_state = "numeric",
    rewards = "numeric"
  ),
  methods = list(
    initialize = function() {
      state <<- 0
      terminal_state <<- 10
      rewards <<- 1:terminal_state
    },
    step = function(action) {
      if (state + action > terminal_state) {
        return(list(state, 0, TRUE))
      }
      state <<- state + action
      reward <<- rewards[state]
      return(list(state, reward, state == terminal_state))
    }
  )
)

Agent <- setRefClass("Agent",
  fields = list(
    alpha = "numeric",
    gamma = "numeric",
    q_table = "numeric"
  ),
  methods = list(
    initialize = function(alpha, gamma) {
      alpha <<- alpha
      gamma <<- gamma
      q_table <<- rep(0, 11)
    },
    choose_action = function(state) {
      if (runif(1) > 0.5) {
        return(1)
      } else {
        return(2)
      }
    },
    learn = function(state, action, reward, next_state) {
      td_target <- reward + gamma * max(q_table[next_state:terminal_state])
      td_error <- td_target - q_table[state + action - 1]
      q_table[state + action - 1] <<- q_table[state + action - 1] + alpha * td_error
    }
  )
)

main <- function() {
  env <- Environment$new()
  agent <- Agent$new(alpha = 0.1, gamma = 0.99)
  episodes <- 1000
  for (i in 1:episodes) {
    state <- env$state
    while (TRUE) {
      action <- agent$choose_action(state)
      next_state <- env$step(action)$state
      reward <- env$step(action)$reward
      done <- env$step(action)$done
      agent$learn(state, action, reward, next_state)
      state <- next_state
      if (done) {
        break
      }
    }
  }
}

main()