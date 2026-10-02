f <- function(a, b) {
    tryCatch({
        return(a / b)
    }, error = function(e) {
        return(Inf)
    })
}

main <- function() {
    result <- f(1.0, 2.0)
    print(result)
}

main()