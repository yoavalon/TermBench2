calculate_altitude <- function(x, y) {
  z <- sqrt(x^2 + y^2)
  return(z)
}

update_position <- function(x, y, dx, dy) {
  nx <- x + dx
  ny <- y + dy
  return(c(nx, ny))
}

main <- function() {
  x <- 0
  y <- 0
  dx <- 1
  dy <- 1
  while (TRUE) {
    xy <- update_position(x, y, dx, dy)
    x <- xy[1]
    y <- xy[2]
    altitude <- calculate_altitude(x, y)
    cat('Position: (', x, ', ', y, '), Altitude: ', altitude, '\n')
  }
}

main()