calculate_reward <- function(state, action) {
  reward <- state + action - sample(0:10, 1)
  return(max(0, reward))
}

update_state <- function(state, action) {
  new_state <- state + action - sample(-5:5, 1)
  return(max(0, new_state))
}

main <- function() {
  state <- sample(10:50, 1)
  action <- sample(1:5, 1)
  reward <- calculate_reward(state, action)
  state <- update_state(state, action)
  cat('Initial State:', state, ', Action:', action, ', Reward:', reward, ', New State:', state, '\n')
}

main()