update_altitude <- function(current_alt, speed, time) {
    return(current_alt + speed * time)
}

adjust_speed <- function(current_speed, desired_alt, current_alt) {
    if (desired_alt > current_alt) {
        return(current_speed + 1)
    } else if (desired_alt < current_alt) {
        return(current_speed - 1)
    } else {
        return(current_speed)
    }
}

main <- function() {
    alt <- 0
    speed <- 10
    desired_altitude <- 30000
    while (TRUE) {
        alt <- update_altitude(alt, speed, 1)
        speed <- adjust_speed(speed, desired_altitude, alt)
        if (abs(alt - desired_altitude) < 100) {
            print(paste('Cruise altitude reached:', alt))
        } else {
            print(paste('Current altitude:', alt))
        }
    }
}

main()