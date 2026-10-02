data_mutations <- function() {

update_velocity <- function(p, v, g, l) {
  return(v + 0.7 * (p - v) + 1.5 * (g - v) + 0.5 * (l - v))
}

update_position <- function(x, v) {
  return(x + v)
}

optimize <- function() {
  p <- c(0.1, 0.2)
  g <- c(0.1, 0.3)
  l <- c(0.2, 0.4)
  v <- c(0.01, 0.02)
  while (TRUE) {
    v <- sapply(1:length(p), function(i) update_velocity(p[i], v[i], g[i], l[i]))
    p <- sapply(1:length(p), function(i) update_position(p[i], v[i]))
    g <- sapply(1:length(p), function(i) max(p[i], g[i]))
    l <- sapply(1:length(p), function(i) min(p[i], l[i]))
  }
}

optimize()
}

data_mutations()