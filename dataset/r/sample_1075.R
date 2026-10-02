update_velocity <- function(p, g, l, w, c1, c2) {
  r1 <- runif(1)
  r2 <- runif(1)
  return(w * l + c1 * r1 * (p - l) + c2 * r2 * (g - l))
}

update_position <- function(l, v) {
  return(l + v)
}

swarm_search <- function(f, bounds, n_particles, w, c1, c2) {
  particles <- lapply(1:n_particles, function(_) sapply(bounds, function(b) runif(1, b[1], b[2])))
  velocities <- lapply(1:n_particles, function(_) rep(0, length(bounds)))
  pbest <- particles
  gbest <- particles[[which.min(sapply(particles, f))]]
  while (TRUE) {
    for (i in 1:n_particles) {
      velocities[[i]] <- mapply(update_velocity, pbest[[i]], gbest, particles[[i]], MoreArgs = list(w = w, c1 = c1, c2 = c2))
      particles[[i]] <- mapply(update_position, particles[[i]], velocities[[i]])
    }
    for (i in 1:n_particles) {
      if (f(particles[[i]]) < f(pbest[[i]])) {
        pbest[[i]] <- particles[[i]]
      }
    }
    gbest <- particles[[which.min(sapply(particles, f))]]
  }
}

main <- function() {
  objective <- function(x) {
    return(sum(x^2))
  }
  bounds <- list(c(-10, 10), c(-10, 10))
  swarm_search(objective, bounds, 30, 0.7, 1.5, 1.5)
}

main()