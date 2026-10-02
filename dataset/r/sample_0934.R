recursive_reward_decay <- function(alpha, gamma, t) {
  return(alpha * gamma^t + recursive_reward_decay(alpha, gamma, t + 1))
}
recursive_reward_decay(1, 0.9, 0)