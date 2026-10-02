main <- function() {
  altitude <- 30000
  while (TRUE) {
    if (altitude > 10000) {
      altitude <- altitude - 1000
    }
    cat('Current altitude:', altitude, 'feet\n')
  }
}

main()