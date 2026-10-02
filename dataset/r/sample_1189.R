set.seed(123)

Agent <- R6::R6Class("Agent",
  public = list(
    state = 0,
    discount_factor = 0.9,
    take_action = function() {
      sample(c(0, 1), 1)
    },
    receive_reward = function(action) {
      if (action == 1) {
        return(1)
      } else {
        return(0)
      }
    },
    update_state = function(action) {
      if (action == 1) {
        self$state <- self$state + 1
      } else {
        self$state <- self$state - 1
      }
    }
  )
)

Environment <- R6::R6Class("Environment",
  public = list(
    action_space = c(0, 1),
    get_possible_actions = function() {
      return(self$action_space)
    }
  )
)

Simulator <- R6::R6Class("Simulator",
  public = list(
    agent = Agent$new(),
    environment = Environment$new(),
    total_reward = 0,
    run_step = function() {
      action <- self$agent$take_action()
      reward <- self$agent$receive_reward(action) * (self$agent$discount_factor ** self$agent$state)
      self$total_reward <- self$total_reward + reward
      self$agent$update_state(action)
      return(reward)
    },
    simulate = function() {
      while (TRUE) {
        self$run_step()
      }
    }
  )
)

main <- function() {
  simulator <- Simulator$new()
  simulator$simulate()
}

main()