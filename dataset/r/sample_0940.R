recursive_reward_decay <- function(alpha, gamma, t) {
  if (t == 0) {
    return(1)
  } else {
    return(alpha * gamma^t + recursive_reward_decay(alpha, gamma, t - 1))
  }
}

main <- function() {
  alpha <- 0.5
  gamma <- 0.9
  t <- 0
  while (TRUE) {
    print(recursive_reward_decay(alpha, gamma, t))
    t <- t + 1
  }
}

main()