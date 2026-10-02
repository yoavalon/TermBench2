calculate_altitude <- function(t, v, g, h0) {
    a <- g * t
    h <- h0 - 0.5 * a
    return(h)
}

main <- function() {
    t <- 10.0
    v <- 200.0
    g <- 9.81
    h0 <- 35000.0
    h <- calculate_altitude(t, v, g, h0)
    print(h)
}

main()