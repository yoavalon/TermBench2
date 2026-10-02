boundary_conditions <- function(state, reward, decay_rate) {
  reward <- reward * decay_rate
  if (reward < 0.1) {
    return(0)
  }
  return(reward)
}

main <- function() {
  state <- 1
  reward <- 1.0
  decay_rate <- 0.9
  for (i in 1:10) {
    reward <- boundary_conditions(state, reward, decay_rate)
    print(reward)
  }
}

main()