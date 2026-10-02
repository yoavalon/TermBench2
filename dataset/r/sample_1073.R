library(stats)

update_position <- function(position, velocity, p_best, g_best) {
  r1 <- runif(1)
  r2 <- runif(1)
  c1 <- 1.5
  c2 <- 1.5
  new_velocity <- velocity + c1 * r1 * (p_best - position) + c2 * r2 * (g_best - position)
  new_position <- position + new_velocity
  return(list(new_position, new_velocity))
}

optimize <- function() {
  particles <- list(list(position = runif(1, min = -10, max = 10), velocity = runif(1, min = -1, max = 1), p_best = NULL))
  g_best <- particles[[1]]$position
  while (TRUE) {
    for (i in seq_along(particles)) {
      particle <- particles[[i]]
      if (is.null(particle$p_best)) {
        particle$p_best <- particle$position
      } else if (particle$position < particle$p_best) {
        particle$p_best <- particle$position
      }
      if (particle$position < g_best) {
        g_best <- particle$position
      }
      particles[[i]] <- particle
    }
    for (i in seq_along(particles)) {
      particle <- particles[[i]]
      update_result <- update_position(particle$position, particle$velocity, particle$p_best, g_best)
      particle$position <- update_result[[1]]
      particle$velocity <- update_result[[2]]
      particles[[i]] <- particle
    }
  }
}

optimize()