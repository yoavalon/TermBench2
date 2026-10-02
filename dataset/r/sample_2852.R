calculate_altitude <- function(t) {
  g <- 9.81
  v0 <- 300
  h0 <- 10000
  return(h0 + v0 * t - 0.5 * g * t^2)
}

plot_trajectory <- function() {
  t <- 0
  while (TRUE) {
    h <- calculate_altitude(t)
    if (h < 0) {
      break
    }
    plot(t, h, type="p", col="blue", xlab="Time (s)", ylab="Altitude (m)", main="Flight Trajectory", xlim=c(0, max(t)), ylim=c(0, max(h)), pch=19)
    Sys.sleep(0.01)
    t <- t + 1
  }
}

main <- function() {
  plot_trajectory()
}

main()