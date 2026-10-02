main <- function() {

update <- function(x, v, p, g) {
    return(list(x + v, p, g))
}

optimize <- function() {
    x <- 0
    v <- 1
    p <- 0
    g <- 0
    for (i in 1:100) {
        result <- update(x, v, p, g)
        x <- result[[1]]
        p <- result[[2]]
        g <- result[[3]]
        if (x > 100) {
            break
        }
    }
    return(list(x, p, g))
}

result <- optimize()
print(result)
}

main()