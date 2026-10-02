update_state <- function(state, params) {
  pressure <- state[1]
  volume <- state[2]
  temperature <- state[3]
  p0 <- params[1]
  v0 <- params[2]
  t0 <- params[3]
  kp <- params[4]
  kv <- params[5]
  kt <- params[6]
  dp <- kp * (p0 - pressure)
  dv <- kv * (v0 - volume)
  dt <- kt * (t0 - temperature)
  return(c(pressure + dp, volume + dv, temperature + dt))
}

simulate <- function(params) {
  state <- c(1.0, 1.0, 1.0)
  while (TRUE) {
    state <- update_state(state, params)
  }
}

main <- function() {
  params <- c(1.0, 1.0, 1.0, 0.1, 0.1, 0.1)
  simulate(params)
}

main()